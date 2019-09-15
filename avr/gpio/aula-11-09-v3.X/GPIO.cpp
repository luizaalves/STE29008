/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include <avr/io.h>
#include "GPIO.h"


GPIO::GPIO(uint8_t id, PortDirection_t dir){
    switch (id) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:{
            if ((id == 0) or (id == 1)) {
                _bit = (1 << id);
            } 
            else if (id == 5) {
                _bit = (1 << (id - 2));
            } 
            else {
                _bit = (1 << (id + 2));
            }
            _Px = GPIO_PORT::PE;
        }
        break;
        case 4:{
            _bit = (1 << (id + 1));
            _Px = GPIO_PORT::PG;
        }
        break;
        case 6:
        case 7:
        case 8:
        case 9:{
            _bit = (1 << (id - 3));
            _Px = GPIO_PORT::PH;
        }
        break;
        case 10:
        case 11:
        case 12:
        case 13:{
            _bit = (1 << (id - 6));
            _Px = GPIO_PORT::PB;
        }
        break;
    }
    _Px->dir(_bit,dir);
}

GPIO::~GPIO() {
}

bool GPIO::get() {
    return _Px->get(_bit);
}

void GPIO::set(bool val) {
    _Px->set(_bit,val);
    
}

void GPIO::clear() {
    _Px->clear(_bit);
}

void GPIO::toggle() {
    _Px->toggle(_bit);
}
