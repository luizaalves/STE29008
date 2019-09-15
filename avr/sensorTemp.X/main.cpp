/* 
 * File:   main.cpp
 * Author: felipe
 *
 * Created on 9 de Setembro de 2019, 09:43
 */


#include <avr/io.h> //ctrl + clicar nele abre o .h; ctrl + f = atmega2560 > ctrl + clicar nele abre o .h
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define F_CPU 16000000L//definir a frequência da cpu, força todas as biblioteca a trabalhem com 16MHz
#define BAUD 9600
#define ubrr_calc F_CPU/16/BAUD-1

#define beta 395000
#define vout_d 753
#define vin 102300000
#define rinf 1763



#include <util/delay.h>

void SERIAL_init();
unsigned char USART_Receive(void);
void USART_Transmit(unsigned char data);
void ADC_init();
unsigned int adc_read();
void led_on();
void led_off();
void calculo_temp();
void imprime_res();
void prints(char x[]);

long temperatura;
unsigned long temp_kelvin;
unsigned long r;
long sensorValue;



int main(int argc, char** argv) {
    DDRB |=(1<<7);
    
    SERIAL_init();
    ADC_init();
    
    for(;;){
        
        led_on();
        calculo_temp();
        led_off();
        imprime_res();
        _delay_ms(1000);
    }
    
    return 0;
}
void SERIAL_init(){
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
void ADC_init(){
    ADMUX = (1<<REFS0);
    ADCSRA = (7<<ADPS0) | (1<<ADEN);
}
unsigned int adc_read(){
    ADCSRA |= (1<<ADSC);
    while(ADCSRA & (1<<ADSC))
        ;
    return ADC;
}

void led_on(){
    PORTB |=(1<<7);// LIGA O LED, colocar zero no portb
}

void led_off(){
    PORTB &=~(1<<7); //APAGA O LED, colocar um no portb       

}
void calculo_temp(){
  sensorValue = adc_read();
  r = 10e3*((vin/sensorValue)-100000);
  temp_kelvin = beta/log(r/rinf);
  temperatura = (temp_kelvin - 27315)/100;

  
}
void imprime_res(){
  char s[20] = ("\ntemperatura: ");
  prints(s);
  char x[sizeof(long)*8+1];
  ltoa(temperatura,x,10);
  prints(x);
}
void prints(char x[]){
    for(int i=0;i< (int)strlen(x);i++)
    USART_Transmit(x[i]);
}
