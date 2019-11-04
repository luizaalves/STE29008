/* 
 * File:   ADC.cpp
 * Author: felipe
 * 
 * Created on 3 de Novembro de 2019, 16:52
 */

#include "ADConverter.h"

ADConverter::ADConverter(REF_t ref, PRESCALER_t clock, CHANNEL_t channel)
{
}

void ADConverter::start_conversion()
{
}

void ADConverter::stop_conversion()
{
}

bool ADConverter::has_data()
{
    return true;
}

uint16_t ADConverter::read()
{
	return 0;
}

void ADConverter::left_adjust()
{
}

void ADConverter::set_channel(CHANNEL_t channel)
{   
}

void ADConverter::set_trigger(TRIGGER_SRC_t src)
{   
}

void ADConverter::enable_interrupt(CALLBACK_t pCallback)
{
    //TODO
    _callback = pCallback;
}
void ADConverter::callback()
{
    (*_callback)();
}
ISR(ADC_vect) {
    ADConverter::callback();
}