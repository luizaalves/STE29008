#include <avr/io.h> 
#include "UART.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdint.h>
#include "Enumeration.h"
#include "Timer.h"
#include "EEPROM.h"
#include <util/delay.h>

void send_dados();
void print_headers();
void verifica_memoria();
EVENT_t sinc(uint8_t op);
EVENT_t config(uint8_t op);
void send_serial(const char* msg);
EVENT_t upload();
EVENT_t read_sensores();
EVENT_t write_mem();
void handle_fsm(EVENT_t event);

#define LIMIT_MEDIDAS 3 // Máximo de medidas que pode ser feita em uma hora
#define TIME_BASE 1000U  // 1 segundo
#define QTD_DADOS 6  // HH MM Umidade Pressao Temperatura Luminosidade
#define POS_FLAG 0
#define POS_INT 1
#define POS_COUNT 2
#define POS_INICIAL_DADOS 3

int j = 1;
uint8_t id_timeout, id_timeoutMedidas, id_timeoutLCD, id_timeoutRelogio;
// tempos padrões
uint32_t timeout = 20 * TIME_BASE; // 20 segundos
uint32_t timeoutMedidas = 4 * TIME_BASE; // 1 minuto
uint32_t timeoutLCD = TIME_BASE/2; // 0.5 segundo
uint32_t timeoutRelogio = TIME_BASE; // 1 segundo

uint8_t intervalo;
uint8_t int_d, int_u;
uint8_t h_d, h_u, m_d, m_u;
uint8_t hora, min;
uint8_t count_medidas;
uint8_t max_medidas;
uint8_t index = 0;
uint8_t index_sinc = 0;
int pos_dados_atual = POS_INICIAL_DADOS;
bool is_min = false;
bool mem_ok = false;

UART _uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
Timer _timer = Timer(1000);
STATE_t _estado_atual = SINC;
EVENT_t _event = NONE;
EEPROM e2prom = EEPROM();
uint8_t dados[6];
Fila<uint8_t, 6>  medidas;

void handle_timeout(void) {
    send_serial("TIMEOUT");
    _event = TIMEOUT;
}

void handle_timeoutMedidas(void) {
    send_serial("TIMEOUT_MEDIDAS");
    count_medidas++;
    e2prom.write((uint8_t*) POS_COUNT, count_medidas);
    _event = TIMEOUT_MEDIDAS;
}

void handle_timeoutLCD(void) {
    send_serial("TIMEOUT_LCD");
}

void handle_timeoutRelogio(void) {
    char x[sizeof (uint8_t)*8 + 1];
    itoa(min, x, 10);
    _uart.put_linha(x);
    if(min == 59){
        if(hora == 23){
            hora = 00;
        }
        min = 00;
    }
    min++;
}

int main(int argc, char** argv) {
    sei();

    verifica_memoria();

    id_timeout = _timer.addTimeout(timeout, &handle_timeout);
    id_timeoutMedidas = _timer.addTimeout(timeoutMedidas, &handle_timeoutMedidas);
    id_timeoutLCD = _timer.addTimeout(timeoutLCD, &handle_timeoutLCD);
    id_timeoutRelogio = _timer.addTimeout(timeoutRelogio, &handle_timeoutRelogio);
    send_serial("Informe hora atual HH:MM seguido de * ");
    _timer.enable_timeout(id_timeout);
    _timer.reload_timeout(id_timeout);


    while (1) {
        if (_event != NONE) {
            handle_fsm(_event);
        }
        _timer.timeoutManager();
        if (_uart.has_data()) {
            uint8_t op = _uart.get();
            if (_estado_atual == IDLE) {
                switch (op) {
                    case 'a':
                    {
                        _event = CONFIG;
                    }
                        break;
                    case 'b':
                    {
                        _event = READ_ATUAL;
                    }
                        break;
                    default:
                    {
                        send_serial("Opcao invalida");
                        send_serial("Opcoes:\na - Config interval\nb - Ler Sensores");
                        _event = NONE;
                    }

                }
            } else if (_estado_atual == WAIT_CONFIG) {
                _event = config(op);

            } else if (_estado_atual == SINC) {
                _event = sinc(op);
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
                char msg[] = "Intervalo de leitura (minutos) seguido de * :";
                send_serial(msg);
                _timer.disable_timeout(id_timeoutMedidas);
                _timer.enable_timeout(id_timeout);
                _timer.reload_timeout(id_timeout);
                _event = NONE;

            }
                break;
            case TIMEOUT_MEDIDAS:
            {
                _estado_atual = READ_2;
                send_serial("Estado - READ_2");
                _timer.disable_timeout(id_timeoutMedidas);
                _event = read_sensores();

            }
                break;
            case READ_ATUAL:
            {
                _estado_atual = READ_1;
                send_serial("Estado - READ_1");
                _timer.disable_timeout(id_timeoutMedidas);
                _timer.disable_timeout(id_timeout);
                _event = read_sensores();
            }
                break;
            default:
            {
                _estado_atual = IDLE;
                _event = NONE;
            }
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
                _event = NONE;
            }
                break;
            case SET_INTERVAL:
            {
                _estado_atual = UPLOAD;
                send_serial("Estado - UPLOAD");
                _timer.disable_timeout(id_timeout);
                _event = upload();
            }
                break;
            default:
            {
                _estado_atual = WAIT_CONFIG;
                _event = NONE;
            }
        }
        //ESTADO READ_2
    } else if (_estado_atual == READ_2) {
        switch (event) {
            case ERRO:
            {
                _estado_atual = IDLE;
                send_serial("Estado - IDLE");
                _timer.enable_timeout(id_timeoutMedidas);
                _event = NONE;
            }
                break;
            case READ_OK:
            {
                _estado_atual = WRITE;
                send_serial("Estado - WRITE");
                _event = write_mem();
            }
                break;
            default:
            {
                _estado_atual = READ_2;
                _event = NONE;
            }
        }
        //ESTADO READ_1
    } else if (_estado_atual == READ_1) {
        if (event == READ_OK) {
            send_serial("leitura atual:");
            _estado_atual = IDLE;
            send_serial("Estado - IDLE");
            _timer.enable_timeout(id_timeoutMedidas);
        }
        _event = NONE;
        //ESTADO WRITE
    } else if (_estado_atual == WRITE) {
        if (event == WRITE_OK) {
            _estado_atual = CHECK;
            send_serial("Estado - CHECK");
            if (count_medidas >= max_medidas) {
                _event = MAX_MEDIDAS;
            } else {
                _event = CHECK_OK;
            }
        } else {
            _event = NONE;
        }

        //ESTADO CHECK
    } else if (_estado_atual == CHECK) {
        switch (event) {
            case MAX_MEDIDAS:
            {
                _estado_atual = UPLOAD;
                send_serial("Estado - UPLOAD");
                _event = upload();
            }
                break;
            case CHECK_OK:
            {
                
                _timer.enable_timeout(id_timeoutMedidas);
                _timer.reload_timeout(id_timeoutMedidas);
                _estado_atual = IDLE;
                send_serial("Estado - IDLE");
                _event = NONE;

            }
                break;
            default:
            {
                _estado_atual = CHECK;
                _event = NONE;
            }
        }

        //ESTADO UPLOAD
    } else if (_estado_atual == UPLOAD) {
        if (event == UP_OK) {
            _estado_atual = SINC;
            count_medidas = 0;
            send_serial("Estado - SINC");
            send_serial("Informe hora atual HH:MM seguido de * ");
            _timer.enable_timeout(id_timeout);
            _timer.reload_timeout(id_timeout);
        }
        _event = NONE;
        //ESTADO SINC
    } else if (_estado_atual == SINC) {
        switch (event) {
            case SINC_OK:
            {
                _timer.disable_timeout(id_timeout);
                _timer.enable_timeout(id_timeoutMedidas);
                _estado_atual = IDLE;
                send_serial("Estado - IDLE");
                _event = NONE;
            }
                break;
            case TIMEOUT:
            {
                _estado_atual = SINC;
                send_serial("Estado - SINC");
                send_serial("Informe hora atual HH:MM seguido de * ");
                _timer.reload_timeout(id_timeout);
                _event = NONE;
            }
                break;
            default:
            {
                _estado_atual = SINC;
                _event = NONE;
            }
        }
    }
}

EVENT_t config(uint8_t op) {
    EVENT_t event = NONE;
    if (op == '*') {
        if (index == 2) {
            intervalo = (int_d * 10) + int_u;
        } else if (index == 1) {
            intervalo = int_d;
        }
        if (index >= 1 && index <= 3) {
            send_serial("CONFIG OK");
            uint32_t interv = intervalo * TIME_BASE;
            _timer.set_intervalTimeout(interv, id_timeoutMedidas);
            e2prom.write((uint8_t*) (POS_INT), intervalo);
            max_medidas = LIMIT_MEDIDAS / intervalo;
            index = 0;
            event = SET_INTERVAL;
        }
    } else if (op >= '0' || op <= '9') {
        if (index == 0) {
            int_d = (op - 48);
            index++;
        } else if (index == 1) {
            int_u = (op - 48);
            index++;
        }
    }
    return event;
}

EVENT_t sinc(uint8_t op) {
    EVENT_t event = NONE;
    if (op == '*') {
        if (index_sinc == 2) {
            min = (m_d * 10) + m_u;
            index_sinc = 0;
        } else if (index_sinc == 1) {
            min = m_d;
            index_sinc = 0;
        }
        is_min = false;
        _timer.enable_timeout(id_timeoutRelogio);
        send_serial("SINC OK");
        event = SINC_OK;

    } else if (op == ':') {
        if (index_sinc == 2) {
            hora = (h_d * 10) + h_u;
            index_sinc = 0;
        } else if (index_sinc == 1) {
            hora = h_d;
            index_sinc = 0;
        }
        is_min = true;

    } else if (op >= '0' || op <= '9') {
        if (index_sinc == 0) {
            if (is_min) {
                m_d = (op - 48);
            } else {
                h_d = (op - 48);
            }
            index_sinc++;
        } else if (index_sinc == 1) {
            if (is_min) {
                m_u = (op - 48);
            } else {
                h_u = (op - 48);
            }
            index_sinc++;
        }
    }
    return event;
}

void verifica_memoria() {
    // uint8_t flag = e2prom.read((uint8_t*) POS_FLAG);
    //    if (flag == 'k') {
    //        intervalo = e2prom.read((uint8_t*) POS_INT);
    //        count_medidas = e2prom.read((uint8_t*) POS_COUNT);
    //        pos_dados_atual = (uint8_t) (count_medidas * QTD_DADOS) + 1;
    //    } else {
    intervalo = 1;
    count_medidas = 0;
    //pos_dados_atual = POS_INICIAL_DADOS;
    //e2prom.write((uint8_t*) POS_FLAG, 'k');
    e2prom.write((uint8_t*) POS_INT, intervalo);
    e2prom.write((uint8_t*) POS_COUNT, count_medidas);
    //}
    max_medidas = LIMIT_MEDIDAS / intervalo;

}

void send_serial(const char* msg) {
    _uart.puts(msg);
}

EVENT_t upload() {
    pos_dados_atual = POS_INICIAL_DADOS;
    uint8_t data;
    int leitura = 0;
    while (leitura < max_medidas) {
        for (int i = 0; i < 6; i++) {
            data = e2prom.read((uint8_t*)pos_dados_atual);
            medidas.push(data);
            pos_dados_atual++;
//            data = e2prom.read((uint8_t*) pos_dados_atual);
//            medidas.push(data);
//            pos_dados_atual++;
//            data = e2prom.read((uint8_t*) pos_dados_atual);
//            medidas.push(data);
//            pos_dados_atual++;
//            data = e2prom.read((uint8_t*) pos_dados_atual);
//            medidas.push(data);
//            pos_dados_atual++;
//            data = e2prom.read((uint8_t*) pos_dados_atual);
//            medidas.push(data);
//            pos_dados_atual++;
//            data = e2prom.read((uint8_t*) pos_dados_atual);
//            medidas.push(data);
//            pos_dados_atual++;
        }
        send_dados();
//        pos_dados_atual++;
        leitura++;
    }
    //    


    //uint8_t leitura = 0;
    //    while (leitura < count_medidas) {
    //        for (int i = 0; i < 6; i++) {
    //            data = e2prom.read((uint8_t*)(i+3));
    //            medidas.push(data);
    //            i++;
    //            //pos_leitura++;
    //        }
    //        send_dados(medidas);
    //        medidas.esvazia();
    //        leitura++;
    //    }
    send_serial("upload");
    return UP_OK;

}

EVENT_t read_sensores() {
    send_serial("lendo_sensores");
    char x[sizeof (uint8_t)*8 + 1];
    itoa(min, x, 10);
    _uart.put_linha(x);

    dados[0] = hora;
    dados[1] = min;
    dados[2] = 23;
    dados[3] = 23;
    dados[4] = 33;
    dados[5] = 33;
    
    return READ_OK;
}

EVENT_t write_mem() {
    send_serial("Escrevendo EEPROM");
    for(int i = 0; i < 6; i++){
        e2prom.write((uint8_t*)pos_dados_atual, dados[i]);
        pos_dados_atual++;
    }
    
    return WRITE_OK;
}

void send_dados() {
    uint8_t byte;
    char x[sizeof (uint8_t)*8 + 1];
    int i = 0;
    while (not medidas.empty()) {
        if(i == 0){
            char sep[] = ":";
            byte = medidas.pop();
            itoa(byte, x, 10);
            _uart.put_linha(x);
            _uart.put_linha(sep);
            i++;
            
        }
        char sep[] = ",";
        byte = medidas.pop();
        itoa(byte, x, 10);
        _uart.put_linha(x);
        _uart.put_linha(sep);
    }
    _uart.put(10); //quebra de linha
}