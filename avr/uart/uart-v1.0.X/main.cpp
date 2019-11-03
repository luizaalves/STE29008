#include <avr/io.h>
#include "UART.h"
#include "fila.h"

Fila<uint8_t,2> fila;

UART uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
 
int main(){
    
	uint8_t echo;
    //fila.push(echo);
	//char msg[] = "Byte Received: ";
 
	while(1){
		echo = uart.get();
		//uart.puts(msg);
        fila.push(echo);
        fila.push(echo);
        if(fila.cheia()){
            uart.put(echo+1);
        }
		uart.put(fila.pop());
        if(!fila.empty()){
            uart.put(fila.pop());
        }
		uart.put('\n');
	}
 
	return 1;
}