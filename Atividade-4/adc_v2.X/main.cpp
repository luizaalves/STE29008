#include <avr/io.h> 
#include <util/delay.h>
#include "UART.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include "extint.h"
#include "Timer.h"
#include "ADConverter.h"

using namespace EXT_INT;

void int0_handler(void);
void intADC_handler(void);
void tx_serial(uint16_t v);

UART uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
Timer t = Timer(1000);

ADConverter adc;
Microseconds temp = 0;          //controlar repique do botão
char value[sizeof (uint16_t)];  //armazenar caracteres referentes ao sensorValue

int main(int argc, char** argv) {
    ExtInt int0(ExtInt::INT_0, ExtInt::RISING, &int0_handler);  
    adc(ADConverter::AVCC, ADConverter::DIV_128, ADConverter::A0);
    uint16_t sensorValue;       //armazenar valor lido do canal ADC
    sei();                      //Ativa interrupção global
    adc.start_conversion();     // Inicia Conversão
    while(not adc.has_data())
        ;
    sensorValue = adc.read();   // bloqueante
    tx_serial(sensorValue);
    //Habilitar Auto Trigger com Free Running
    adc.set_trigger(ADConverter::FREE_RUN);
    for(int i = 0; i < 5; i++){
        while(not adc.has_data())
            ;
        sensorValue = adc.read();
        tx_serial(sensorValue);
    }
    adc.stop_conversion();
    //Habilitar Auto Trigger com EXT_INT0 e interrupção
    int0.enable(); //Habilita interrupção externa INT0
    adc.set_trigger(ADConverter::EXT_INT0);
    adc.enable_interrupt(&intADC_handler);
    adc.start_conversion();
    for (;;) {}

    return 0;
}
void tx_serial(uint16_t v){
    ltoa(v, value, 10);
    uart.puts(value);
}
void int0_handler(void) {
    return;
}
void intADC_handler(void) {
    tx_serial(adc.read());
    return;
}
