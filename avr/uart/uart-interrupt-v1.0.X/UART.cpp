/* 
 * File:   UART.cpp
 * Author: aluno
 * 
 * Created on 16 de Setembro de 2019, 08:12
 */

#include <avr/io.h>

#include "UART.h"
#define F_CPU 16000000L

UART::UART(uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb){
    UBRR0 = F_CPU/16/baud-1;
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0); 
    UCSR0C = (db | parity | sb);
}

UART::~UART() {
}

uint8_t UART::get(){
    _has_data = false;
    return _rx_buffer;
}
void UART::put(uint8_t data){
    _tx_buffer = data;
    UCSR0B |= (1 << UDRIE0);
}

bool UART::has_data(){
    return _has_data;
}

static void UART::rx_isr_handler(){
    _rx_buffer = UDR0;
    _has_data = true;
}

static void UART::tx_isr_handler(){
    UDR0 = _tx_buffer;
    UCSR0B &= ~(1 << UDRIE0);
}

