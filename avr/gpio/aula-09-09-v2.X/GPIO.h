/* 
 * File:   GPIO.h
 * Author: aluno
 *
 * Created on 9 de Setembro de 2019, 07:51
 */

#ifndef GPIO_H
#define	GPIO_H

class GPIO {
public:
    enum PortDirection_t {
        INPUT = 0,
        OUTPUT = 1
    };
    
    GPIO(uint8_t id, PortDirection_t dir);
    ~GPIO();

    bool get();
    void set(bool val = 1);
    void clear();
    void toggle();

private:
    volatile uint8_t * _pin; //entrada
    volatile uint8_t * _ddr; //endereço
    volatile uint8_t * _port; //saída
    
    uint8_t _id;
    uint8_t _bit;
};



#endif	/* GPIO_H */

