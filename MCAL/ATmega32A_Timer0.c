/*
 * ATmega32A_Timer0.c
 *
 * Created: 9/9/2019 8:23:48 PM
 *  Author: Hamdy
 */ 
#include <ATmega32A_Timer0.h>
#include <stdio.h>
#include <avr/interrupt.h>

void (* volatile Timer0_ISR_OVF)(void) = NULL;
void (* volatile Timer0_ISR_COMP)(void) = NULL;

ISR(TIMER0_OVF_vect)
{
	if (Timer0_ISR_OVF != NULL)
	{
		Timer0_ISR_OVF();
	}
}
ISR(TIMER0_COMP_vect)
{
	if (Timer0_ISR_COMP != NULL)
	{
		Timer0_ISR_COMP();
	}
}
	void Timer0_Init(
						Timer0_Clock Clk,
						Timer0_Modes Mode,
						Timer0_CmpOutMode CmpMode,
						Timer0_InterruptControl IntMode
						)
						{
							TCCR0->Data = Clk | Mode | CmpMode;
							TIMSK->Data &= 0xFC;
							TIMSK->Data |= IntMode;
						}
						
						
	void Timer0_SquareSignal_Out(
									float32 F_Timer,
									float32 F_Required)
									{
										float32 Temp= (F_Timer / (2*F_Required))-1;
										GPIO_DirectionSet(GPIOB,PIN3,OUTPUT);
										if (Temp > 255 || Temp < 0)
										{
											printf("Error , Invalid OCR0 Value \n");
											printf("Please ReConsider The Freq Values \n");
											while(1)
											{
												
											}
										}
										
										OCR0->Data = (uint8_t)(Temp + 0.5);
									}
									
void Timer0_PWM(float32 DutyCycle ,Timer0_CmpOutMode OutMode )
{
	GPIO_DirectionSet(GPIOB,PIN3,OUTPUT);
	switch (OutMode)
	{
		case 0x20:
								OCR0->Data = (255 * (DutyCycle/100.0))+0.5;
		break;
		case 0x30:
							    OCR0->Data = (255 * ((100-DutyCycle)/100.0))+0.5;
		break;
		default:
		printf("Invalid Input \n");
		break;
	}
}