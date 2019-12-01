/* 
 * File:   LDR.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 23:24
 */

#ifndef LDR_H
#define	LDR_H

#include "ADConverter.h"


class LDR {
public:
    LDR();
    uint16_t read();
    void start();
private:
    //ADConverter _adc;

};

#endif	/* LDR_H */

