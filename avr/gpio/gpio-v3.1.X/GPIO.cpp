/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include <avr/io.h>
#include "GPIO.h"
namespace GPIO {

GPIO * GPIO::_ExtInt_singletons[8];

GPIO::GPIO(uint8_t id, PortDirection_t dir)
{
	_bit = GPIO_PORT::id_to_bit[id];
	_port = GPIO_PORT::AllPorts[GPIO_PORT::id_to_port[id]];
	_port->dir(_bit, dir);
}

GPIO::GPIO(GPIO::INT_ID_t id, GPIO::ISC_t cfg, CALLBACK_t pCallback)
:_bit(id)
{

}

bool GPIO::get() {
    return _port->get(_bit);
}

void GPIO::set(bool val) {
    _port->set(_bit,val);
    
}

void GPIO::clear() {
    _port->clear(_bit);
}

void GPIO::toggle() {
    _port->toggle(_bit);
}

ISR(INT0_vect)
{GPIO::_ExtInt_singletons[0]->callback();}

ISR(INT1_vect)
{GPIO::_ExtInt_singletons[1]->callback();}

ISR(INT2_vect)
{GPIO::_ExtInt_singletons[2]->callback();}

ISR(INT3_vect)
{GPIO::_ExtInt_singletons[3]->callback();}

ISR(INT4_vect)
{ExtInt::_ExtInt_singletons[4]->callback();}

ISR(INT5_vect)
{ExtInt::_ExtInt_singletons[5]->callback();}


}