#include <avr/io.h> 
#include <util/delay.h>
#include "UART.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdint.h>
#include "extint.h"
#include "ADConverter.h"

using namespace EXT_INT;

//void int0_handler(void);
void tx_serial(uint16_t v);
uint16_t calcula_media();


//ExtInt int0 = ExtInt(ExtInt::INT_0, ExtInt::FALLING, &int0_handler); 

UART uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
ADConverter adc = ADConverter(ADConverter::AVCC, ADConverter::DIV_128);
char value[sizeof (uint16_t)];  //armazenar caracteres referentes ao sensorValue

int main(int argc, char** argv) {
     
    //int0.enable(); //Habilita interrupção externa INT0
    sei();                      //Ativa interrupção global
    uart.puts("Bloqueante");
    for(int i=0;i < 10;i++){
        uint16_t single = adc.single_read(ADConverter::A0);
        tx_serial(single); //Bloqueante
        _delay_ms(1000);
    }
    
    uart.puts("Free Running");
    adc.read(ADConverter::A0,50,ADConverter::FREE_RUN);
    for (;;) {
        if(adc.free()) 
            tx_serial(calcula_media());  
    }
    return 0;
}
uint16_t calcula_media(){
    uint16_t media = 0;
    unsigned int size = ADConverter::_buffer.size();
    while(not ADConverter::_buffer.empty()){
        media = media + ADConverter::_buffer.pop();
    }
    adc.read(ADConverter::A0,50,ADConverter::FREE_RUN);
    return media/size;

}

void tx_serial(uint16_t v){
    ltoa(v, value, 10);
    uart.puts(value);
}
//void int0_handler(void) {
//    return;
//}
