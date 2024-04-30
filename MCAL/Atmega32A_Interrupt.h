/*
 * Atmega32A_Interrupt.h
 *
 * Created: 8/20/2019 7:34:24 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_INTERRUPT_H_
#define ATMEGA32A_INTERRUPT_H_

	#include "uC_Config.h"
	#include "Common_Macros.h"
	#include "STDTypes.h"
	#include "ATmega32A_GPIO.h"
	
	extern void (* volatile ISR0_ptr)(void);
	extern void (* volatile ISR1_ptr)(void);
	extern void (* volatile ISR2_ptr)(void);
	
	#define SREG		((volatile reg8 *)0x5f)
	#define MCUCR		((volatile reg8 *)0x55)
	#define MCUCSR		((volatile reg8 *)0x54)
	#define GICR		((volatile reg8 *)0x5B)
	#define GIFR		((volatile reg8 *)0x5A)
	
	#define GLOBAL_INETERRUPT_ENABLE()		{SREG->Bits.B7 = 1;}
	#define GLOBAL_INETERRUPT_DISABLE()		{SREG->Bits.B7 = 0;}
		
	typedef enum
	{
		Interrupt0,
		Interrupt1,
		Interrupt2,
	}Atmega32A_ExternalInterrupts;
	
	typedef enum
	{
		RisingMode,
		FallingMode,
		BothEdges,
		LOW_Level,
	}Ex_InterruptModes;
	
	
void Ext_InterruptEnable(
							Atmega32A_ExternalInterrupts int_num,
							Ex_InterruptModes  Mode);	
	
void Ext_InterruptDisable(Atmega32A_ExternalInterrupts int_num);


void	ExInt_UserWarning_Error (void);

#endif /* ATMEGA32A_INTERRUPT_H_ */