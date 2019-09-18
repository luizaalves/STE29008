#include <avr/io.h>
#include "UART.h"
#include <avr/interrupt.h>

UART uart(115200, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
 
int main(){
    sei();
	while(1){
		if(uart.has_data()){
            uart.put(uart.get());
        }
	}
 
	return 1;
}