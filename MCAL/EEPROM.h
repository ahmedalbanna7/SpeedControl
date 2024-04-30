/*
 * EEPROM.h
 *
 * Created: 4/27/2020 2:30:08 AM
 *  Author: ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/eeprom.h>
	#include <util/delay.h>

void eeprom_write(unsigned int address, unsigned char data);
unsigned char eeprom_read(unsigned char address);


#endif /* EEPROM_H_ */