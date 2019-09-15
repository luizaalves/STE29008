/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include <avr/io.h>
#include "GPIO.h"

GPIO::GPIO(uint8_t id, PortDirection_t dir){
    _id = id;
    switch (_id) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:{
            if ((_id == 0) or (_id == 1)) {
                _bit = id;
            } 
            else if (_id == 5) {
                _bit = id - 2;
            } 
            else {
                _bit = id + 2;
            }
            _ddr = &DDRE;
            _port = &PORTE;
            _pin = &PINE;
        }
        break;
        case 4:{
            _bit = id + 1;
            _ddr = &DDRG;
            _port = &PORTG;
            _pin = &PING;
        }
        break;
        case 6:
        case 7:
        case 8:
        case 9:{
            _bit = id - 3;
            _ddr = &DDRH;
            _port = &PORTH;
            _pin = &PINH;
        }
        break;
        case 10:
        case 11:
        case 12:
        case 13:{
            _bit = id - 6;
            _ddr = &DDRB;
            _port = &PORTB;
            _pin = &PINB;
        }
        break;
    }
    if (dir) {
        *_ddr |= (1 << _bit);  //OUTPUT
    } 
    else {
        *_ddr &= ~(1 << _bit); //INPUT
    }
}


GPIO::~GPIO() {
}

bool GPIO::get() {
    return *_pin & (1 << _bit);
}

void GPIO::set(bool val) {
    if(val){
        *_port |= (1 << _bit);
    }
    else{
        *_port &= ~(1 << _bit);
    }

}

void GPIO::clear() {
    this->set(0);
}

void GPIO::toggle() {
    *_pin = (1 << _bit);
}
