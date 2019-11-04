#ifndef A_D_C_H
#define A_D_C_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "REF_t.h"
#include "PRESCALER_t.h"
#include "uint16_t.h"
#include "CHANNEL_t.h"
#include "TRIGGER_SRC_t.h"
#include "CALLBACK_t.h"

class ADC
{
public:
	void ADC(REF_t ref, PRESCALER_t clock);

	void start_conversion();

	uint16_t read(CHANNEL_t chan);

	void left_adjust();

	void set_trigger(TRIGGER_SRC_t src);

	void enable_interrupt(CALLBACK_t pCallback);

};
#endif
