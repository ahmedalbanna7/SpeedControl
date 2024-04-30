/*
 * Keypad.h
 *
 * Created: 9/11/2019 11:13:39 PM
 *  Author: ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <uC_Config.h>
#include <STDTypes.h>
#include <ATmega32A_GPIO.h>


#define KEY_PRT  GPIOA->Port.Data
#define KEY_DDR  GPIOA->DDR.Data
#define KEY_PIN  GPIOA->Pin.Data

char keyfind();

#endif /* KEYPAD_H_ */