/* 
 * File:   Sensor.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 21:33
 */

#ifndef SENSOR_H
#define	SENSOR_H

#include <avr/io.h>

class Sensor {
public:
    Sensor(){}
    virtual int32_t read();
    virtual void start();
private:
    
};

#endif	/* SENSOR_H */

