/*
 * MotorDriver_L298D.c
 *
 * Created: 9/15/2019 5:55:08 PM
 *  Author: Hamdy
 */ 

#include <MotorDriver_L298D.h>

void MotorControl(MotorControlBlock Mpin , MotorStats State, float32 Speed)
{
	
	if (Mpin.SpeedControl_Enable == 0)
	{
		switch(State)
		{
			case Motor_Stop:
			GPIO_OutputHandle(Mpin.Ch1_Port,Mpin.Ch1_pin,LOW);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,LOW);
			break;
			case Motor_MoveFW:
			GPIO_OutputHandle(Mpin.Ch1_Port,Mpin.Ch1_pin,HIGH);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,LOW);
			break;
			case Motor_MoveBack:
			GPIO_OutputHandle(Mpin.Ch1_Port,Mpin.Ch1_pin,LOW);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,HIGH);
			break;
			case Motor_Break:
			GPIO_OutputHandle(Mpin.Ch1_Port,Mpin.Ch1_pin,HIGH);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,HIGH);
			break;
			default:
			break;
		}
	}
	else
	{
		switch(State)
		{
			case Motor_Stop:
			Timer0_PWM(0,PWM_FastNonInvert);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,LOW);
			break;
			case Motor_MoveFW:
			Timer0_PWM(Speed,PWM_FastNonInvert);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,LOW);
			break;
			case Motor_MoveBack:
			Timer0_PWM(Speed,PWM_FastNonInvert);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,HIGH);
			break;
			case Motor_Break:
			Timer0_PWM(0,PWM_FastNonInvert);
			GPIO_OutputHandle(Mpin.Ch2_Port,Mpin.Ch2_Pin,LOW);
			break;
			default:
			break;
		}
	}
	
}