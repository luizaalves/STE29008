#include <avr/io.h> 
#include "UART.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdint.h>
#include "Enumeration.h"
#include "Timer.h"

void send_serial(const char* msg);
void upload();
void read_sensores();
void write_mem(const char* data);
void handle_fsm(EVENT_t event);

uint8_t id_timeout, id_timeoutMedidas, id_timeoutLCD;
// tempos padrões
uint32_t timeout = 10000;        // 10 segundos
uint32_t timeoutMedidas = 60000; // 60 segundos
uint32_t timeoutLCD = 1000;      // 1 segundo

void handle_timeout(void) {
    send_serial("TIMEOUT");
    handle_fsm(TIMEOUT);
}

void handle_timeoutMedidas(void) {
    send_serial("TIMEOUT_MEDIDAS");
    handle_fsm(TIMEOUT_MEDIDA);
}
void handle_timeoutLCD(void) {
    send_serial("TIMEOUT_LCD");
}

UART _uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
Timer _timer = Timer(1000);
STATE_t _estado_atual = IDLE;
int main(int argc, char** argv) {
    sei();
    id_timeout = _timer.addTimeout(10000, &handle_timeout);
    id_timeoutMedidas = _timer.addTimeout(30000, &handle_timeoutMedidas);
    id_timeoutLCD = _timer.addTimeout(1000, &handle_timeoutMedidas);
    send_serial("Estado - IDLE");
    _timer.enable_timeout(id_timeoutMedidas);
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
                        send_serial("Opção inválida");
                        send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
                    }

                }
            }
            else if(_estado_atual == WAIT_CONFIG){
                if(op == '*'){
                    send_serial("CONFIG OK");
                    handle_fsm(SET_INTERVAL);
                }
            }
            else if(_estado_atual == SINC){
                if(op == '*'){
                    send_serial("SINC OK");
                    handle_fsm(SINC_OK);
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
                char msg[] = "Informe o intervalo de leitura:";
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
            case TIMEOUT_MEDIDA:
            {
                _estado_atual = READ_2;
                send_serial("Estado - READ_2");
                enable_timeout = true;
                enable_timeoutMedidas = false;
                read_sensores();

            }
                break;
            case READ_ATUAL:
            {
                _estado_atual = READ_1;
                send_serial("Estado - READ_1");
                enable_timeout = false;
                enable_timeoutMedidas = false;
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
                enable_timeout = false;
                enable_timeoutMedidas = true;
                send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            }
                break;
            case SET_INTERVAL:
            {
                _estado_atual = UPLOAD;
                send_serial("Estado - UPLOAD");
                enable_timeout = false;
                enable_timeoutMedidas = false;
                upload();
            }
                break;
            default: _estado_atual = WAIT_CONFIG;
        }
    //ESTADO READ_2
    } else if (_estado_atual == READ_2) {
        switch (event) {
            case TIMEOUT:
            {
                _estado_atual = IDLE;
                send_serial("Estado - IDLE");
                enable_timeout = false;
                enable_timeoutMedidas = true;
                send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            }
                break;
            case READ_OK:
            {
                _estado_atual = WRITE;
                send_serial("Estado - WRITE");
                enable_timeout = false;
                enable_timeoutMedidas = false;
                write_mem("Escrita Memoria");
            }
                break;
            default: _estado_atual = READ_2;
        }
    //ESTADO READ_1
    } else if (_estado_atual == READ_1) {
        if (event == READ_OK) {
            _estado_atual = IDLE;
            send_serial("leitura atual:");
            send_serial("Estado - IDLE");
            send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            enable_timeout = false;
            enable_timeoutMedidas = true;
        }
    //ESTADO WRITE
    } else if (_estado_atual == WRITE) {
        if (event == WRITE_OK) {
            _estado_atual = IDLE;
            send_serial("Estado - IDLE");
            send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            enable_timeout = false;
            enable_timeoutMedidas = true;
        }
    //ESTADO UPLOAD
    } else if (_estado_atual == UPLOAD) {
        if (event == UP_OK) {
            _estado_atual = SINC;
            send_serial("Estado - SINC");
            send_serial("Informe hora atual:");
        }
    //ESTADO SINC
    } else if (_estado_atual == SINC) {
        if (event == SINC_OK) {
            _estado_atual = IDLE;
            send_serial("Estado - IDLE");
            send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
            enable_timeout = false;
            enable_timeoutMedidas = true;
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