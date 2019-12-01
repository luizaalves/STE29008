/* 
 * File:   Principal.cpp
 * Author: felipe
 * 
 * Created on 30 de Novembro de 2019, 23:28
 */

#include "Enumeration.h"
Principal::Principal() 
: _uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1),  _timer(1000) 
{
   
}

int Principal::main(int argc, char** argv){
    sei();
    _timer.addTimeout(1000, &handle_timeout);
    while (1){
        _timer.timeoutManager();
        if(_uart.has_data()){
            uint8_t op = _uart.get();
            switch(op){
                case 'a' : {
                    this->handle_fsm(CONFIG);
                }
                break;
                case 'b' : {
                    this->handle_fsm(READ_ATUAL);
                }
                break;
                default : this->send_serial("Opção inválida\n");
            
            }
        }
    }
}

void Principal::handle_fsm(EVENT_t event){
    //ESTADO IDLE
    if(_estado_atual == IDLE){
        switch(event)
        {
            case CONFIG : {
                _estado_atual = WAIT_CONFIG;
                char msg[]= "Informe o intervalo de leitura:";
                send_serial(msg);
            }
            break;
            case MAX_MEDIDAS : {
                _estado_atual = UPLOAD;
                this->upload();
            }
            break;
            case TIMEOUT_MEDIDA : {
                _estado_atual = READ_2;
                this->read_sensores();
                
            }
            break;
            case READ_ATUAL : {
                _estado_atual = READ_1;
                this->read_sensores();
            }
            break;
            default : _estado_atual = IDLE;
        }
    }
    else if(_estado_atual == WAIT_CONFIG){
        switch(event)
        {
            case TIMEOUT : {
                _estado_atual = IDLE;
                this->send_serial("Opcoes:\na - Config interval\nb - Ler Sensores\n");
            }
            break;
            case SET_INTERVAL : {
                _estado_atual = UPLOAD;
                this->upload();
            }
            break;
            default : _estado_atual = WAIT_CONFIG;
        }
    }
    else if(_estado_atual == READ_2){
        switch(event)
        {
            case TIMEOUT : {
                _estado_atual = IDLE;
                this->send_serial("Opcoes:\na - Config interval\nb - Ler Sensores\n");
            }
            break;
            case READ_OK : {
                _estado_atual = WRITE;
                this->write_mem("Escrita Memoria");
            }
            break;
            default : _estado_atual = READ_2;
        } 
        
    }
    else if(_estado_atual == READ_1){
        if(event == READ_OK){
            _estado_atual = IDLE;
            this->send_serial("leitura atual:");
            this->send_serial("Opcoes:\na - Config interval\nb - Ler Sensores\n");
        }
        
    }
    else if(_estado_atual == WRITE){
        if(event == WRITE_OK){
            _estado_atual = IDLE;
            this->send_serial("Opcoes:\na - Config interval\nb - Ler Sensores\n");
        } 
    }
    else if(_estado_atual == UPLOAD){
        if(event == UP_OK){
            _estado_atual = SINC;
            this->send_serial("Informe hora atual:");
        } 
    }
    else if(_estado_atual == SINC){
        if(event == SINC_OK){
            _estado_atual = IDLE;
            this->send_serial("Opcoes:\na - Config interval\nb - Ler Sensores\n");
        } 
    }
}
void Principal::handle_timeout(void){
    handle_fsm(TIMEOUT);
}

void Principal::send_serial(const char* msg){
    _uart.puts(msg);
}
void Principal::upload(){
    this->send_serial("upload\n");
}
void Principal::read_sensores(){
    this->send_serial("lendo sensores\n");
}