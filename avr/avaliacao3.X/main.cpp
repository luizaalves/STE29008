/* 
 * File:   main.cpp
 * Author: Felipe Cardoso
 * 
 * Created on 9 de Setembro de 2019, 08:03
 */

/**
 tamanho do main() - 182 bytes
 tamanho do write_byte() - 6 bytes
 */

#include <avr/io.h>
#include "GPIO_Port.h"
#include "GPIO.h"
#include "Timer.h"
#include "UART.h"
#include <avr/interrupt.h>
 

GPIO botao(54, GPIO::INPUT);		//PF0
GPIO_PORT::GPIO_Port * PK;

void timeout2_handler(void);

UART uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
Timer t = Timer(1000);
uint8_t leds = 0x01;

int main(void){
    sei();
    PK = GPIO_PORT::AllPorts[9];
    PK->dir_byte(GPIO::OUTPUT);
    PK->write_byte(leds);
    t.addTimeout(1000, &timeout2_handler);
    Microseconds temp = 0;
	while (1){
        t.timeoutManager();
        if(botao.get()){
            if((t.millis() - temp) > 1000){
                temp = t.millis();
                uart.put(leds);
            }
        }
    }
}
void timeout2_handler(void){
  
    PK->write_byte(leds);
    leds = (leds << 1);
    if(leds == 0x00) leds = 0x01;
}