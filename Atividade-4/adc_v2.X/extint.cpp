/*
 * extint.cpp
 *
 *  Created on: May 18, 2018
 *      Author: roberto
 */

#include "extint.h"

namespace EXT_INT {

ExtInt * ExtInt::_ExtInt_singletons[8];

ExtInt::ExtInt(ExtInt::INT_ID_t id, ExtInt::ISC_t cfg, CALLBACK_t pCallback)
:_id(id)
{
	_msk = (_id % 4) << 1;	// _id mod 4 * 2 (4 interrupts per EICRx register)

	disable();

	if (_id < INT_4){
		EICRA = (EICRA & ~(3 << _msk)) | (cfg << _msk);
	}
	else{
		EICRB = (EICRB & ~(3 << _msk)) | (cfg << _msk);
	}

	_ExtInt_singletons[_id] = this;
	_pCallback = pCallback;

	//External Interrupt Flag should be clear after EICRn modifications
	//and before interrupt re-enable (pag. 110)
	EIFR |= (1<<_id);


}

ExtInt::~ExtInt(){}

void ExtInt::enable(){
	EIMSK |= (1 <<_id);
}

void ExtInt::disable(){
	EIMSK &= ~(1<<_id);
}


ISR(INT0_vect)
{ExtInt::_ExtInt_singletons[0]->callback();}

ISR(INT1_vect)
{ExtInt::_ExtInt_singletons[1]->callback();}

ISR(INT2_vect)
{ExtInt::_ExtInt_singletons[2]->callback();}

ISR(INT3_vect)
{ExtInt::_ExtInt_singletons[3]->callback();}

ISR(INT4_vect)
{ExtInt::_ExtInt_singletons[4]->callback();}

ISR(INT5_vect)
{ExtInt::_ExtInt_singletons[5]->callback();}

ISR(INT6_vect)
{ExtInt::_ExtInt_singletons[6]->callback();}

ISR(INT7_vect)
{ExtInt::_ExtInt_singletons[7]->callback();}



}
