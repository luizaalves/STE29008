
#include <avr/io.h> //ctrl + clicar nele abre o .h; ctrl + f = atmega2560 > ctrl + clicar nele abre o .h
#include <util/delay.h>
#include "UART.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include "GPIO.h"

void ADC_init();
void tx_serial();
void on_led();
//unsigned int adc_read();

UART uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
GPIO led(2,GPIO::OUTPUT);

int main(int argc, char** argv) {   

    ADC_init();
    sei();
    ADCSRA |= (1<<ADSC);
    for(;;){
        //_delay_ms(1000);
        //sensorValue = adc_read();        
    }
    
    return 0;
}
void ADC_init(){
    ADMUX = (1<<REFS0);
    ADCSRA = (7<<ADPS0) | (1<<ADEN) | (1<<ADIE);
    
    
}
//unsigned int adc_read(){
//    //ADCSRA |= (1<<ADSC);
//    //while(ADCSRA & (1<<ADSC))
//        //;
//    //return ADC;
//}
ISR(ADC_vect){
    
    switch(ADMUX){
        case 0x40 : {
            long sensorValue = ADC;
            //DIDR0 = (1<<ADC0D);
            char x[sizeof(long)*8+1];
            ltoa(sensorValue,x,10);
            //uart.puts("Leu 1");
            uart.puts(x);   
            ADMUX = 0x41;
            _delay_ms(1000);
        }
        break;
        case 0x41 : {
            long sensorValue2 = ADC;
            //DIDR0 = (1<<ADC1D);
            char x[sizeof(long)*8+1];
            ltoa(sensorValue2,x,10);
            //uart.puts("Leu 2");
            uart.puts(x);   
            ADMUX = 0x40;
            _delay_ms(1000);
        }
        break;
        default : 
            break;
    
    }
    ADCSRA |= (1<<ADSC);
}
