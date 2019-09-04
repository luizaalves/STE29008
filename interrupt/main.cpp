/* 
 * File:   exemplo1.cpp
 * Author: aluno
 *
 * Created on 28 de Agosto de 2019, 07:58
 */


#include <avr/io.h> //ctrl + clicar nele abre o .h; ctrl + f = atmega2560 > ctrl + clicar nele abre o .h
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL//definir a frequência da cpu, força todas as biblioteca a trabalhem com 16MHz
#define BAUD 9600
#define ubrr_calc F_CPU/16/BAUD-1

void setup();
unsigned char USART_Receive(void);
void USART_Transmit(unsigned char data);

int main(int argc, char** argv) {

    setup();
	sei();
	EICRB |= (3<<ISC40);
	EIMSK |= (1<<INT4);
    DDRB |= (1<<7);//DDRB configurando o pino b7 como saida
    DDRE &= ~(1<<4); //DDRB configurando o pino pe4 como entrada
    //PB7 SAÍDA E PE4B6 ENTRADA
    //PORTB | = (1<<7);// LIGA O LED, colocar zero no portb
    //PORTB & = ~(1<<7); //APAGA O LED, colocar um no portb       
    
             //PORTB &= ~(1<<7);//DESLIGA O LED
       //_delay_ms(1000);
    for(;;){ //tem que por o looping
       if(PINE & (1<<4)){ //ler do pine se a chave está pressionada
           USART_Transmit('a'); 
       } 

       PORTB |= (1<<7); //liga o led
       _delay_ms(1000);
       PORTB &= ~(1<<7);//DESLIGA O LED
       _delay_ms(1000);
       
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
