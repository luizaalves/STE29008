/* 
 * File:   GPIO.h
 * Author: aluno
 *
 * Created on 9 de Setembro de 2019, 07:51
 */

#ifndef GPIO_H
#define	GPIO_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "GPIO_Port.h"
namespace GPIO {

typedef void (*CALLBACK_t) (void);

class GPIO {
public:
    enum ISC_t {		//Interrupt Sense Control
		LOW_LEVEL = 0,
		ANY_EDGE = 1,
		FALLING = 2,
		RISING = 3
	};

	enum INT_ID_t {		//Interrupt Sense Control
		INT_0 = 0,
		INT_1 = 1,
		INT_2 = 2,
		INT_3 = 3,
		INT_4 = 4,
		INT_5 = 5,
		INT_6 = 6,
		INT_7 = 7,
	};
    
    enum PortDirection_t {
        INPUT = 0,
        OUTPUT = 1,
    };
    
    GPIO(uint8_t id, PortDirection_t dir);
    GPIO(INT_ID_t id,
		   ISC_t cfg,
		   CALLBACK_t pCallback);

    //Metodos para EXTINT
	void enable();
	void disable();
	void callback(){(*_pCallback)();}
    static GPIO * _ExtInt_singletons[8];
    
    //Metodos para GPIO
    bool get();
    void set(bool val = 1);
    void clear();
    void toggle();

private:
    GPIO_PORT::GPIO_Port * _port; 
    uint8_t _bit;
    CALLBACK_t _pCallback;
};
}


#endif	/* GPIO_H */

