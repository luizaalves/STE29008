/* 
 * File:   ADC.cpp
 * Author: felipe
 * 
 * Created on 3 de Novembro de 2019, 16:52
 */

#include "ADConverter.h"

ADConverter::ADConverter(REF_t ref, PRESCALER_t clock) {
    ADMUX | = (ref<<REFS0);
    ADCSRA | =(clock<<ADPS0) | (1<<ADEN);
    _read_free = false;
}
ADConverter::select_channel(CHANNEL_t channel){
    //Zerando inicialmente caso tenha algo da inicialização antiga
    ADMUX & =~(31<<MUX0);
    ADCSRB =0x00;
    
    if(channel<=channel.A7)
        ADMUX |= (channel<<MUX0);
    else {
        ADCSRB |= (1<<MUX5);
        ADMUX |= channel & ~(1<<5);
    }
}

ADConverter::read(CHANNEL_t channel, uint8_t count, TRIGGER_SRC_t mode){
    if(not _read_free){
        _read_free=true;
        select_channel(channel);
        _count = count;
        _count_event=0;
        _event=false;
        ADCSRA |=(1<<ADIE);
        ADCSRB |= (mode<<ADTS0);
        ADCSRA |=(1<<ADATE);
    }
    
}

bool ADConverter::free(){
    
    return _event;
}
uint16_t ADConverter::single_read(CHANNEL_t channel){
    select_channel(channel);
    
    ADCSRA | =(1<<ADSC);
    while(ADCSRA & (1<<ADSC))
        ;
    return ADC;
}

void ADConverter::stop_conversion(){
    ADCSRA & =~(1<<ADATE);
    ADCSRA & =~(1<<ADIE);
}

void ADConverter::left_adjust(){
    ADMUX = (1<<ADLAR);
}
void ADConverter::handler(){
    _count_event++;
    _buffer.push(ADC);
    if(_count_event==_count){
        stop_conversion();
        _event=true;
        _read_free = false;
    }
}

ISR(ADC_vect) {
    ADConverter::handler();
}