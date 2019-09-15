/* 
 * File:   main.cpp
 * Author: aluno
 * 
 * Created on 9 de Setembro de 2019, 08:03
 */


#include <avr/io.h>
#include "GPIO.h"
#include "GPIO_Port.h"

#define F_CPU 16000000L
#include <util/delay.h>
 
//LEDS PLACA (acende com '0')
GPIO led0(0, GPIO::OUTPUT);		//PE0
GPIO led1(1, GPIO::OUTPUT);		//PE1
 
//LEDS PLACA (acende com '1')
//GPIO led13(13, GPIO::OUTPUT);	//PB7
 
//Adicionar LED
GPIO led4(4, GPIO::OUTPUT);		//PG5
GPIO led6(6, GPIO::OUTPUT);		//PH0

GPIO ledt(GPIO_PORT::Ports_index.PA_i, GPIO::OUTPUT);
 
int main(void){
 
	UCSR0B = 0;
 
	led0.set(1);
	led1.set(1);
	led6.clear();
	led4.clear();
	ledt.clear();
	_delay_ms(1000);
	led0.clear();
	led1.clear();
	led6.set(1);
	led4.set(1);
	ledt.set(1);
	_delay_ms(1000);
 
	while (1){
		led0.toggle();
		led1.toggle();
		led6.toggle();
		led4.toggle();
		ledt.toggle();
		_delay_ms(1000);
	}
 
}