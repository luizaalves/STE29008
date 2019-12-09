/*
 * EEPROM.cpp
 *
 *  Created on: 25 de jun de 2019
 *      Author: paulosell
 */

#include "EEPROM.h"

void EEPROM::write(uint8_t * pos, uint8_t byte){
	eeprom_write_byte(pos, byte);
}

void EEPROM::write32(uint32_t * pos, uint32_t byte){
	eeprom_write_dword(pos, byte);
}

void EEPROM::write_burst(uint8_t * pos, Fila<uint8_t,6> * bytes){
	uint8_t * _pos = pos;
	while(!bytes->empty()){
		eeprom_write_byte(_pos, bytes->pop());
		_pos++;

	}
}

uint8_t EEPROM::read(uint8_t * pos){
	return eeprom_read_byte(pos);
}

uint32_t EEPROM::read32(uint32_t * pos){
	return eeprom_read_dword(pos);
}

Fila<uint8_t, 6> read_burst(uint8_t * pos, uint8_t num_bytes){
	Fila<uint8_t, 6> fila;
	uint8_t * _pos = pos;

	for(int i = 0; i < num_bytes; i++){
		fila.push(eeprom_read_byte(_pos));
		_pos++;
	}
	return fila;
}

