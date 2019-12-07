#include <avr/io.h> 
#include "UART.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdint.h>
#include "Enumeration.h"
#include "Timer.h"
#include "EEPROM.h"

void send_serial(const char* msg);
void upload();
void read_sensores();
void write_mem(const char* data);
void handle_fsm(EVENT_t event);

uint8_t id_timeout, id_timeoutMedidas, id_timeoutLCD;
// tempos padrões
uint32_t timeout = 60000;        // 10 segundos
uint32_t timeoutMedidas = 60000; // 60 segundos
uint32_t timeoutLCD = 1000;      // 1 segundo

uint8_t intervalo = 1;
uint8_t hora, min;
uint8_t count_medidas = 0;  
uint8_t max_medidas = 3;

bool is_min = false;

void handle_timeout(void) {
    send_serial("TIMEOUT");
    handle_fsm(TIMEOUT);
}

void handle_timeoutMedidas(void) {
    send_serial("TIMEOUT_MEDIDAS");
    count_medidas++;
    if(count_medidas < max_medidas){
        handle_fsm(TIMEOUT_MEDIDAS);   
    }
    else{
        send_serial("MAX_MEDIDAS");
        count_medidas = 0;
        handle_fsm(MAX_MEDIDAS);
    }
           
}
void handle_timeoutLCD(void) {
    send_serial("TIMEOUT_LCD");
}
UART _uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
Timer _timer = Timer(1000);
STATE_t _estado_atual = SINC;
EEPROM e2prom;

int main(int argc, char** argv) {
    sei();
    id_timeout = _timer.addTimeout(timeout, &handle_timeout);
    id_timeoutMedidas = _timer.addTimeout(timeoutMedidas, &handle_timeoutMedidas);
    id_timeoutLCD = _timer.addTimeout(timeoutLCD, &handle_timeoutLCD);
    send_serial("Informe hora atual (HH:MM)");
    _timer.enable_timeout(id_timeout);
    while (1) {
        _timer.timeoutManager();
        if (_uart.has_data()) {
            uint8_t op = _uart.get();
            if (_estado_atual == IDLE) {
                switch (op) {
                    case 'a':
                    {
                        handle_fsm(CONFIG);
                    }
                        break;
                    case 'b':
                    {
                        handle_fsm(READ_ATUAL);
                    }
                        break;
                    case '\n':
                    {
                    }
                        break;
                    default:
                    {
                        send_serial("Opcao invalida");
                        send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
                    }

                }
            }
            else if(_estado_atual == WAIT_CONFIG){
                if(op == '*'){
                    send_serial("CONFIG OK");
                    handle_fsm(SET_INTERVAL);
                }
                else{
                    intervalo = op-48;
                    uint32_t interv = intervalo*1000;
                    _timer.set_intervalTimeout(interv, id_timeoutMedidas);                    
                }
            }
            else if(_estado_atual == SINC){
                if(op == ':'){
                    is_min = true;
                }
                else if(op == '*'){
                    send_serial("SINC OK");
                    handle_fsm(SINC_OK);
                }
                else if(is_min){
                    min = op;
                }
                else{
                    hora = op;
                }
                
            }
        }
    }
    return 0;
}

void handle_fsm(EVENT_t event) {
    //ESTADO IDLE
    if (_estado_atual == IDLE) {
        switch (event) {
            case CONFIG:
            {
                _estado_atual = WAIT_CONFIG;
                send_serial("Estado - WAIT_CONFIG");
                char msg[] = "Informe o intervalo de leitura (minutos):";
                send_serial(msg);
                _timer.disable_timeout(id_timeoutMedidas);
                _timer.enable_timeout(id_timeout);
                
            }
                break;
            case MAX_MEDIDAS:
            {
                _estado_atual = UPLOAD;
                send_serial("Estado - UPLOAD");
                _timer.disable_timeout(id_timeoutMedidas);
                upload();
            }
                break;
            case TIMEOUT_MEDIDAS:
            {
                _estado_atual = READ_2;
                send_serial("Estado - READ_2");
                _timer.disable_timeout(id_timeoutMedidas);
                read_sensores();

            }
                break;
            case READ_ATUAL:
            {
                _estado_atual = READ_1;
                send_serial("Estado - READ_1");
                _timer.disable_timeout(id_timeoutMedidas);
                _timer.enable_timeout(id_timeout);
                read_sensores();
            }
                break;
            default: _estado_atual = IDLE;
        }
    //ESTADO WAIT_CONFIG    
    } else if (_estado_atual == WAIT_CONFIG) {
        switch (event) {
            case TIMEOUT:
            {
                _estado_atual = IDLE;
                send_serial("Estado - IDLE");
                _timer.disable_timeout(id_timeout);
                _timer.enable_timeout(id_timeoutMedidas);
                //send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            }
                break;
            case SET_INTERVAL:
            {
                _estado_atual = UPLOAD;
                send_serial("Estado - UPLOAD");
                _timer.disable_timeout(id_timeout);
                upload();
            }
                break;
            default: _estado_atual = WAIT_CONFIG;
        }
    //ESTADO READ_2
    } else if (_estado_atual == READ_2) {
        switch (event) {
            case ERRO:
            {
                _estado_atual = IDLE;
                send_serial("Estado - IDLE");
                _timer.enable_timeout(id_timeoutMedidas);
                //send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            }
                break;
            case READ_OK:
            {
                _estado_atual = WRITE;
                send_serial("Estado - WRITE");
                write_mem("Escrita Memoria");
            }
                break;
            default: _estado_atual = READ_2;
        }
    //ESTADO READ_1
    } else if (_estado_atual == READ_1) {
        if (event == READ_OK) {
            send_serial("leitura atual:");
            _estado_atual = IDLE;
            send_serial("Estado - IDLE");
            //send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            _timer.enable_timeout(id_timeoutMedidas);
        }
    //ESTADO WRITE
    } else if (_estado_atual == WRITE) {
        if (event == WRITE_OK) {
            _estado_atual = IDLE;
            send_serial("Estado - IDLE");
            //send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            _timer.enable_timeout(id_timeoutMedidas);
        }
    //ESTADO UPLOAD
    } else if (_estado_atual == UPLOAD) {
        if (event == UP_OK) {
            _estado_atual = SINC;
            send_serial("Estado - SINC");
            send_serial("Informe hora atual (HH:MM)");
            _timer.enable_timeout(id_timeout);
        }
    //ESTADO SINC
    } else if (_estado_atual == SINC) {
        switch(event){
            case SINC_OK : {
                _timer.disable_timeout(id_timeout);
                _timer.enable_timeout(id_timeoutMedidas);
                _estado_atual = IDLE;
                send_serial("Estado - IDLE");
                //send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            }
            break;
            case TIMEOUT: {
                _estado_atual = SINC;
                send_serial("Estado - SINC");
                send_serial("Informe hora atual (HH:MM)");
            }
            break;
            default : _estado_atual = SINC;
        }
    }
}

void send_serial(const char* msg) {
    _uart.puts(msg);
}

void upload() {
    send_serial("upload");
    handle_fsm(UP_OK);
}

void read_sensores() {
    send_serial("lendo_sensores");
    handle_fsm(READ_OK);
}

void write_mem(const char* data) {
    send_serial(data);
    handle_fsm(WRITE_OK);
}