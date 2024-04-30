/*
 * ATmega32A_FirmWare.c
 *
 * Created: 8/4/2019 9:17:00 PM
 *  Author: Hamdy
 */ 

#include <MotorDriver_L298D.h>
#include <ATmega32A_Timer0.h>

int main(void)

{
	MotorControlBlock FrontWheel = {GPIOB,PIN2,GPIOB,PIN3,1};
	Timer0_Init(Timer0_FCPU_DIV64,T0_FASTPWM,PWM_FastNonInvert,Timer0_InterruptDisable);
	GPIO_DirectionSet(GPIOB,PIN2,OUTPUT);
	GPIO_DirectionSet(GPIOB,PIN3,OUTPUT);
	int8_t i =0;
	while(1)
    {		
		for(i=0;i<=100;i+=10)
		{
			MotorControl(FrontWheel,Motor_MoveFW,i);
			_delay_ms(500);
		}
		
		for(i=100;i>=0;i-=10)
		{
			MotorControl(FrontWheel,Motor_MoveFW,i);
			_delay_ms(500);
		}
		MotorControl(FrontWheel,Motor_Stop,i);
		_delay_ms(2500);
		
    }
}

