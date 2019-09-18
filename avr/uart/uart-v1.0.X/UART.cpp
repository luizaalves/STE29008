/* 
 * File:   UART.cpp
 * Author: aluno
 * 
 * Created on 16 de Setembro de 2019, 08:12
 */

#include "UART.h"

#define F_CPU 16000000L

UART::UART(uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb){
    UBRR0 = F_CPU/16/baud-1;
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0); 
    UCSR0C = (db | parity | sb);
}

UART::~UART() {
}

uint8_t UART::get(){
    while (!(UCSR0A & (1 << RXC0)))
        ;

    return UDR0;
}
void UART::put(uint8_t data){
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = data;
}
void UART::puts(const char* msg){
    for(int i=0;msg[i] != 0; ++i)
        put((uint8_t) msg[i]);
}
