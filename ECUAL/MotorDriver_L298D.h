/*
 * MotorDriver_L298D.h
 *
 * Created: 9/15/2019 5:55:18 PM
 *  Author: Hamdy
 */ 


#ifndef MOTORDRIVER_L298D_H_
#define MOTORDRIVER_L298D_H_


	#include <uC_Config.h>
	#include <STDTypes.h>
	#include <Common_Macros.h>
	#include <ATmega32A_Timer0.h>
	#include <ATmega32A_GPIO.h>

typedef enum
{
	Motor_Stop,
	Motor_MoveFW,
	Motor_MoveBack,
	Motor_Break,
}MotorStats;

typedef struct  
{
	gio * Ch1_Port;
	PINS  Ch1_pin;
	
	gio * Ch2_Port;
	PINS  Ch2_Pin;
	
	uint8_t SpeedControl_Enable:1; // Set This pin to 1 to Enable Speed Control
}MotorControlBlock;
void MotorControl(MotorControlBlock Mpin , MotorStats State , float32 Speed);
#endif /* MOTORDRIVER_L298D_H_ */