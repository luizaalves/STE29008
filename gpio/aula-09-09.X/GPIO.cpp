/* 
 * File:   GPIO.cpp
 * Author: aluno
 * 
 * Created on 9 de Setembro de 2019, 08:03
 */

#include "GPIO.h"
#include <avr/io.h>

GPIO::GPIO() {
}

GPIO::GPIO(uint8_t id, PortDirection_t dir) {
    _id = id;
    switch(_id){
        case 0:
        case 1: {
            _bit = _id;
            if(dir == GPIO.INPUT){
                DDRE &= ~(1<<_bit); 
            }
            else {
                DDRE |= (1<<_bit); 
            }
        }
        break;
        case 2:
        case 3: {
            _bit = _id+2;
            if(dir == GPIO.INPUT){
                DDRE &= ~(1<<_bit); 
            }
            else {
                DDRE |= (1<<_bit); 
            }
        }
        break;
        case 4: {
            _bit = _id+1;
            if(dir == GPIO.INPUT){
                DDRG &= ~(1<<_bit); 
            }
            else {
                DDRG |= (1<<_bit); 
            }
        }  
        break;
        case 5: {
            _bit = _id-2;
            if(dir == GPIO.INPUT){
                DDRE &= ~(1<<_bit); 
            }
            else {
                DDRE |= (1<<_bit); 
            }
        } 
        break;
        case 6:
        case 7:
        case 8:
        case 9: {
            _bit = _id-3;
            if(dir == GPIO.INPUT){
                DDRH &= ~(1<<_bit); 
            }
            else {
                DDRH |= (1<<_bit); 
            }
        }   
        break;
        case 10:
        case 11:
        case 12:
        case 13: {
            _bit = _id-6;
            if(dir == GPIO.INPUT){
                DDRB &= ~(1<<_bit); 
            }
            else {
                DDRB |= (1<<_bit); 
            }
        }
        break;   
    }
    
}

GPIO::~GPIO() {
}

bool get(){
    
}
void set(bool val = 1){
    
}
void clear(){

}
void toggle(){

}

