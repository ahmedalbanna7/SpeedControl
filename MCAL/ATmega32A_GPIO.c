/*
 * ATmega32A_GPIO.c
 *
 * Created: 8/6/2019 6:17:56 PM
 *  Author: Hamdy
 */ 
#include "ATmega32A_GPIO.h"


void GPIO_DirectionSet(
						volatile gio* Current_Gpio,
						PINS pin_number,
						IO_Modes  Mode)
{
		switch (Mode)
		{
			case INPUT_FLOAT:
				 if (pin_number != ALLRegister)
				 {
					 CLEARBIT(Current_Gpio->DDR.Data,pin_number);
					 CLEARBIT(Current_Gpio->Port.Data,pin_number);
				 }
				 else
				 {
					 Current_Gpio->DDR.Data=0;
					 Current_Gpio->Port.Data=0;
				 }
			break;
			case INPUT_PULLUP:
				  if (pin_number != ALLRegister)
				  {
					  CLEARBIT(Current_Gpio->DDR.Data,pin_number);
					  SETBIT(Current_Gpio->Port.Data,pin_number);
				  }
				  else
				  {
					  Current_Gpio->DDR.Data=0;
					  Current_Gpio->Port.Data=0xff;
				  }
			break;
			case OUTPUT:
				  if (pin_number != ALLRegister)
				  {
					  SETBIT(Current_Gpio->DDR.Data,pin_number);
					  CLEARBIT(Current_Gpio->Port.Data,pin_number);
				  }
				  else
				  {
					  Current_Gpio->DDR.Data=0xff;
					  Current_Gpio->Port.Data=0;
				  }
			break;
			default:
			break;
		}
									
}

void GPIO_OutputHandle(
						volatile gio* Current_Gpio,
						PINS pin_number,
						DigitalValues Value)
{
	 if (pin_number != ALLRegister)
	 {
		if ( Value == HIGH)
		{
			SETBIT(Current_Gpio->Port.Data,pin_number);
		}
		else
		{
			CLEARBIT(Current_Gpio->Port.Data,pin_number);
		}
	 }
	 else
	 {
		 Current_Gpio->Port.Data = Value;
	 }
}

DigitalValues GPIO_InputHandle(
								volatile gio* Current_Gpio,
								PINS pin_number)
{
	 if (pin_number != ALLRegister)
	 {
		 if(READBIT(Current_Gpio->Pin.Data , pin_number) == 1)
		 {
			return HIGH; 
		 }
		 else
		 {
			 return LOW;
		 }
	 }
	 else
	 {
		 return Current_Gpio->Port.Data;
	 }
}