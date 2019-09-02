/* 
 * File:   exemplo1.cpp
 * Author: aluno
 *
 * Created on 28 de Agosto de 2019, 07:58
 */


#include <avr/io.h> //ctrl + clicar nele abre o .h; ctrl + f = atmega2560 > ctrl + clicar nele abre o .h

#define F_CPU 16000000L//definir a frequência da cpu, força todas as biblioteca a trabalhem com 16MHz
#define BAUD 9600
#define ubrr_calc F_CPU/16/BAUD-1

void setup();
unsigned char USART_Receive(void);
void USART_Transmit(unsigned char data);

int main(int argc, char** argv) {

    setup();
    unsigned char buffer;
    
    
    for(;;){
        buffer = USART_Receive();
        USART_Transmit(buffer+1);        
    }
    
    return 0;
} 
void setup(){
    UBRR0  = ubrr_calc;
    UCSR0C = (3<<UCSZ00);
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    
}

unsigned char USART_Receive(void) {
    /* Wait for data to be received */
    while (!(UCSR0A & (1 << RXC0)))
        ;
    /* Get and return received data from buffer */
    return UDR0;
}

void USART_Transmit(unsigned char data) {
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}