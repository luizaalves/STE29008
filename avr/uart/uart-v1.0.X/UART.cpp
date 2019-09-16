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

