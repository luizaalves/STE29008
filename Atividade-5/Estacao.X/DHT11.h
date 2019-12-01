/* 
 * File:   DHT11.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 23:26
 */

#ifndef DHT11_H
#define	DHT11_H

#include "GPIO.h"
#include "Sensor.h"


class DHT11: public Sensor {
public:
    DHT11();
    uint16_t read();
    void start();
private:
    //GPIO _gpio;
};

#endif	/* DHT11_H */

