/*
 * ATmega32A_Timer0.h
 *
 * Created: 9/9/2019 8:23:57 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_TIMER0_H_
#define ATMEGA32A_TIMER0_H_

	#include <STDTypes.h>
	#include <Common_Macros.h>
	#include <uC_Config.h>
	#include <Atmega32A_Interrupt.h>
	

	#define TCCR0 ((volatile reg8 * )0x53)
	#define TCNT0 ((volatile reg8 * )0x52)
	#define OCR0  ((volatile reg8 *) 0x5C)
	#define TIMSK ((volatile reg8 *) 0x59)
	#define TIFR  ((volatile reg8 *) 0x58)
	
	typedef enum
	{
		T0_NormalMode=0x00,
		T0_CTCMode=0x08,
		T0_FASTPWM=0x48,
		T0_PhaseCorrectPWM=0X40,
	}Timer0_Modes;
	
	typedef enum
	{
		Timer_outDisabled=0x00,
		Toggle_TimerOut=0x10,
		Clear_TimerOut=0x20,
		Set_TimerOut=0x30,
		PWM_FastNonInvert=0x20,
		PWM_FastInvert=0x30,
		PWM_PhaseCorrect_NonInvert=0x20,
		PWM_PhaseCorrect_Invert=0x30,
	}Timer0_CmpOutMode;
	
	typedef enum
	{
		Timer0_Disable,
		Timer0_FCPU,
		Timer0_FCPU_DIV8,
		Timer0_FCPU_DIV64,
		Timer0_FCPU_DIV256,
		Timer0_FCPU_DIV1024,
		Timer0_ExternalClock_FallEdge,
		Timer0_ExternalClock_RisingEdge,
	}Timer0_Clock;
	typedef enum
	{
		Timer0_InterruptDisable,
		Timer0_OVF_IntEnable,
		Timer0_COMP_IntEnable,
		Timer0_COMP_OVF_IntEnable,
	}Timer0_InterruptControl;
	
	
	static inline void ForceCompare(void)
	{
		TCCR0->Bits.B7=1;
	}	
	
	void Timer0_Init(
						Timer0_Clock Clk,
						Timer0_Modes Mode,
						Timer0_CmpOutMode CmpMode,
						Timer0_InterruptControl IntMode
						);
						
	void Timer0_SquareSignal_Out(
								  float32 F_Timer,
								  float32 F_Required);
								  
	void Timer0_PWM(float32 DutyCycle ,Timer0_CmpOutMode OutMode );
	extern void (* volatile Timer0_ISR_OVF )(void);
	extern void (* volatile Timer0_ISR_COMP)(void);
#endif /* ATMEGA32A_TIMER0_H_ */