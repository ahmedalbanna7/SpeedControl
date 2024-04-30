/*
 * ATmega32A_GPIO.h
 *
 * Created: 8/6/2019 6:17:45 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_GPIO_H_
#define ATMEGA32A_GPIO_H_

#include <Common_Macros.h>
#include <uC_Config.h>
#include <STDTypes.h>

#define GPIOA		((volatile gio *)0x39)
#define GPIOB		((volatile gio *)0x36)
#define GPIOC		((volatile gio *)0x33)
#define GPIOD		((volatile gio *)0x30)

typedef enum
{
	LOW,
	HIGH,
}DigitalValues;

typedef enum
{
	INPUT_FLOAT,
	INPUT_PULLUP,
	OUTPUT,	
}IO_Modes;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	ALLRegister,
}PINS;


typedef union
{
	vuint8_t Data;
	struct
	{
		vuint8_t B0:1;
		vuint8_t B1:1;
		vuint8_t B2:1;
		vuint8_t B3:1;
		vuint8_t B4:1;
		vuint8_t B5:1;
		vuint8_t B6:1;
		vuint8_t B7:1;
	}Bits;
}reg8;



typedef struct 
{
	volatile reg8 Pin;
	volatile reg8 DDR;
	volatile reg8 Port;
}gio;


void GPIO_DirectionSet(
						volatile gio* Current_Gpio,
						PINS pin_number,
						IO_Modes  Mode);
						
void GPIO_OutputHandle(
						volatile gio* Current_Gpio,
						PINS pin_number,
						DigitalValues Value);
						
DigitalValues GPIO_InputHandle(
								volatile gio* Current_Gpio,
								PINS pin_number);
#endif /* ATMEGA32A_GPIO_H_ */