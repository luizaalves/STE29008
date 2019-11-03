#include <avr/io.h> 
#include <util/delay.h>
#include "UART.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include "extint.h"
#include "Timer.h"

using namespace EXT_INT;

void ADC_setup();
void ADC_start();
void int0_handler(void);

UART uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
Timer t = Timer(1000);
Microseconds temp = 0;        //controlar repique do botão
uint16_t sensorValue;             //valor lido do canal ADC
char value[sizeof (uint16_t)];  //armazenar caracteres referentes ao sensorValue

int main(int argc, char** argv) {
    ExtInt int0(ExtInt::INT_0, ExtInt::RISING, &int0_handler);

    int0.enable(); //Habilita interrupção externa INT0
    ADC_setup();  //Configura ADC
    sei();        //Ativa interrupção global
    ADC_start();  //Inicia Conversão
    for (;;) {
    }

    return 0;
}

void ADC_setup() {
    ADMUX = (1 << REFS0);     // Referência do AVCC (5 Volts)
    ADCSRA = (7 << ADPS0) | (1 << ADEN)   // Clock ADC e Habilita ADC
            | (1 << ADIE) | (1 << ADATE); // Habilita Interrupção e Auto Trigger
    ADCSRB = (1 << ADTS1);    // Habilita INT0 como fonte do Auto Trigger
}

void ADC_start() {
    ADCSRA |= (1 << ADSC);
}

void int0_handler(void) {
    return;
}

ISR(ADC_vect) {
    if ((t.millis() - temp) > 1000) {
        temp = t.millis();
        sensorValue = ADC;
        ltoa(sensorValue, value, 10);
        uart.puts(value);
    }
}