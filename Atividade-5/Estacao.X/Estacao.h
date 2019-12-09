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

template<int max_sensores> class Estacao {
public:

    Estacao() {
        _n_sensores = 0;
        _max_sensores = max_sensores;
    }

    void readALL(long * leituras) {
        for (int i = 0; i < _max_sensores; i++) {
            leituras[i] = _sensores[i]->read();
        }
    }

    void addSensor(Sensor * sensor) {
        if (_n_sensores < _max_sensores) {
            _sensores[_n_sensores] = sensor;
            _n_sensores++;
        }


    }
    void writeLCD(const char * msg){
    
    
    }
private:
    Sensor * _sensores[max_sensores];
    uint8_t _max_sensores;
    LCD _lcd;
    uint8_t _n_sensores;
};

#endif	/* ESTACAO_H */

