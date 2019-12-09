/* 
 * File:   BMP280.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 23:25
 */

#ifndef BMP280_H
#define	BMP280_H

#include "SPI.h"
#include "Sensor.h"


class BMP280 : public Sensor {
public:
    BMP280();
    int32_t read();
    void start();
private:
    //SPI _spi;
};

#endif	/* BMP280_H */

