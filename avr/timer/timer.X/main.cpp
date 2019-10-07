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

GPIO led13(13,GPIO::OUTPUT);
GPIO_PORT::GPIO_Port * pk  = GPIO_PORT::AllPorts[9];

uint8_t pk_value = 0x01;

Timer t = Timer(1000);

void rotate_pk(void){
    pk->write_byte(pk_value);
    if(pk_value == 128) pk_value = 0x01;
        
    else pk_value<<=1;
}

int main(void){
 //não usar o delay, usar o timer
    led13.clear();
    
    pk->dir_byte(1);

    t.addTimeout(2000,&rotate_pk);
    
    for(;;){
        t.timeoutManager();
    }
    return 0;
	
 
}