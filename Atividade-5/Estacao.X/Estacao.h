/* 
 * File:   Estacao.h
 * Author: felipe
 *
 * Created on 30 de Novembro de 2019, 21:40
 */

#ifndef ESTACAO_H
#define	ESTACAO_H

#include "Sensor.h"
#include "LCD.h"

class Estacao {
public:
    Estacao();
    char * readALL();
    void addSensor(Sensor sensor);
    void writeLCD(const char * msg);
private:
    Sensor _sensores[3];
    LCD _lcd;
};

#endif	/* ESTACAO_H */

