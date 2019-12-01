/* 
 * File:   LCD.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 21:58
 */

#ifndef LCD_H
#define	LCD_H

#include "GPIO.h"
#include "GPIO_Port.h"


using namespace GPIO_PORT;


class LCD {
public:
    LCD();
private:
    GPIO_Port _gpio_port;
};

#endif	/* LCD_H */

