/*
 * Atmega32A_Interrupt.c
 *
 * Created: 8/20/2019 7:34:16 PM
 *  Author: Hamdy
 */ 


#define _AVR_ATMEGA32A_H_INCLUDED


#include <Atmega32A_Interrupt.h>
#include <avr/interrupt.h>
#include <stdio.h>

	 void (* volatile ISR0_ptr)(void)=NULL;
	 void (* volatile ISR1_ptr)(void)=NULL;
	 void (* volatile ISR2_ptr)(void)=NULL;

ISR(INT0_vect)
{
	if (ISR0_ptr != NULL)
	{
		ISR0_ptr();
	}	
	
}


ISR(INT1_vect)
{
	if (ISR1_ptr != NULL)
	{
		ISR1_ptr();
	}
}
ISR(INT2_vect)
{
	if (ISR2_ptr != NULL)
	{
		ISR2_ptr();
	}
}

void ExInt_UserWarning_Error(void)
{
	while(1)
	{
		printf("!! SomeThing Went Wrong !! Please Re Check Your Settings !!");
	}
}

void Ext_InterruptEnable(Atmega32A_ExternalInterrupts int_num,Ex_InterruptModes  Mode)
{
	 switch (int_num)
	 {
		 case Interrupt0:
			  if      (Mode == RisingMode)
			  {
				  MCUCR->Bits.B0=1;
				  MCUCR ->Bits.B1=1;
			  }
			  else if (Mode	== FallingMode)
			  {
				  MCUCR ->Bits.B0=0;
				  MCUCR ->Bits.B1=1;
			  }
			  else if (Mode == BothEdges)
			  {
				  MCUCR ->Bits.B0=1;
				  MCUCR ->Bits.B1=0;
			  }
			  else if (Mode == LOW_Level)
			  {
				  MCUCR ->Bits.B0=0;
				  MCUCR ->Bits.B1=0;
			  }
			  else
			  {
				  ExInt_UserWarning_Error();
			  }
			  /* this Line Enables External Interrupt 0 */
			  GICR->Bits.B6=1;
		 break;
		 case Interrupt1:
			  if      (Mode == RisingMode)
			  {
				  MCUCR ->Bits.B3=1;
				  MCUCR ->Bits.B2=1;
			  }
			  else if (Mode	== FallingMode)
			  {
				  MCUCR ->Bits.B3=1;
				  MCUCR ->Bits.B2=0;
			  }
			  else if (Mode == BothEdges)
			  {
				  MCUCR ->Bits.B3=0;
				  MCUCR ->Bits.B2=1;
			  }
			  else if (Mode == LOW_Level)
			  {
				  MCUCR ->Bits.B3=0;
				  MCUCR ->Bits.B2=0;
			  }
			  else
			  {
				  ExInt_UserWarning_Error();
			  }
			  /* this Line Enables External Interrupt 1 */
			  GICR->Bits.B7=1;
		 break;
		 case Interrupt2:
			  if      (Mode == RisingMode)
			  {
				 MCUCSR->Bits.B6=1; 
			  }
			  else if (Mode	== FallingMode)
			  {
				  MCUCSR->Bits.B6=0; 
			  }
			  else
			  {
				  ExInt_UserWarning_Error();
			  }
			  /* this Line Enables External Interrupt 2 */
			  GICR->Bits.B5=1;
		 break;
		 default:
				  ExInt_UserWarning_Error();
		 break;
	 }
}

void Ext_InterruptDisable(Atmega32A_ExternalInterrupts int_num)
{
	
	switch (int_num)
	{
		case Interrupt0:
			 GICR->Bits.B6=0;
		break;
		case Interrupt1:
			 GICR->Bits.B7=0;
		break;
		case Interrupt2:
			 GICR->Bits.B5=0;
		break;
		default:
			 ExInt_UserWarning_Error();
		break;
	}
	
}
