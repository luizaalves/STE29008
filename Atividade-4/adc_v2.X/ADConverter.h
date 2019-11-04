/* 
 * File:   ADC.h
 * Author: felipe
 *
 * Created on 3 de Novembro de 2019, 16:52
 */

#ifndef ADConverter_H
#define	ADConverter_H

#include <avr/io.h>
typedef void (*CALLBACK_t) (void);

class ADConverter {
public:

    enum CHANNEL_t {
        A0 = 0,
        A1 = 1,
        A2 = 2,
        A3 = 3,
        A4 = 4,
        A5 = 5,
        A6 = 6,
        A7 = 7,
        A8 = 32,
        A9 = 33,
        A10 = 34,
        A11 = 35,
        A12 = 36,
        A13 = 37,
        A14 = 38,
        A15 = 39
    };

    enum REF_t {
        AREF = 0,
        AVCC = 1,
        V1_1 = 2,
        V2_56 = 3
    };

    enum PRESCALER_t {
        DIV_2 = 0,
        DIV_4 = 2,
        DIV_8 = 3,
        DIV_16 = 4,
        DIV_32 = 5,
        DIV_64 = 6,
        DIV_128 = 7
    };

    enum TRIGGER_SRC_t {
        FREE_RUN = 0,
        COMP_ANALOG = 1,
        EXT_INT0 = 2,
        COMP_A_T0 = 3,
        OVF_T0 = 4,
        COMP_B_T1 = 5,
        OVF_T1 = 6,
        EVENT_T1 = 7,
    };
    
    ADConverter(REF_t ref, PRESCALER_t clock, CHANNEL_t channel);
     
    void start_conversion();
    void stop_conversion();
    bool has_data();
    uint16_t read();
    void left_adjust();
    void set_channel(CHANNEL_t channel);
    void set_trigger(TRIGGER_SRC_t src);
    void enable_interrupt(CALLBACK_t pCallback);
    static void callback();
    
private:
    static CALLBACK_t _callback;
};

#endif	/* ADConverter_H */

