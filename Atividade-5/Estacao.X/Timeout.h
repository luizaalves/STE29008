/* 
 * File:   Timeout.h
 * Author: aluno
 *
 * Created on 25 de Setembro de 2019, 08:10
 */

#ifndef TIMEOUT_H
#define	TIMEOUT_H

#include <avr/io.h>


typedef void (*CALLBACK_t) (void);

class Timeout {
    
public:
    Timeout();
    void config(uint32_t interval,CALLBACK_t callback);
    void checkTimeout();
    void callback();
    void inc_counter();
    //Inserido para Atividade-5
    bool enabled();
    void enable(bool op);
    void set_interval(uint32_t interv);
    void reload();
    //---
private:
    bool _event;
    bool _enable;
    CALLBACK_t _callback;
    uint32_t _counter;
    uint32_t _interval;  

};

#endif	/* TIMEOUT_H */

