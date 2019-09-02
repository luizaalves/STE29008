/* 
 * File:   exemplo1.cpp
 * Author: aluno
 *
 * Created on 28 de Agosto de 2019, 07:58
 */


#include <avr/io.h> //ctrl + clicar nele abre o .h; ctrl + f = atmega2560 > ctrl + clicar nele abre o .h


int main(int argc, char** argv) {

    setup();
       
    unsigned int vout_d;
    
    for(;;){
        ADCSRA |= (1<<ADSC);
        vout_d = adc_read();
        //TODO - implementar envio pela serial
        
    }
    
    return 0;
}
void setup(){
    ADMUX = (1<<REFS0);
    ADCSRA = (7<<ADPS0) | (1<<ADEN);
}
unsigned int adc_read(){
    while(ADCSRA & (1<<ADSC))
        ;
    return ADC;
}
