/* 
 * File:   BMP280.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 23:25
 */

#ifndef BMP280_H
#define	BMP280_H

#include "SPI.h"


class BMP280 {
public:
    BMP280();
    uint16_t read();
    void start();
private:
    //SPI _spi;
};

#endif	/* BMP280_H */

