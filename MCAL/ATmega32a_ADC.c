/*
 * ATmega32a_ADC.c
 *
 * Created: 9/8/2019 8:23:17 PM
 *  Author: Hamdy
 */ 


#include <ATmega32a_ADC.h>

	void ADC_Init(
					ADC_RefernceVolt Ref,
					ADC_WorkMode Int_Mode,
					ADC_ConvMode ConvMode,
					ADC_PreScale Freq_PreScale)
	{

		ADMUX->Data = Ref;
		ADCSRA->Data = ADC_Enable | Int_Mode | ConvMode | Freq_PreScale;		
	}
	
	void ADC_Disable(void)
	{
		ADCSRA->Data = ADC_Dis;
	}
	
	uint16_t ADC_Read_Polling(
	ADC_Chanel Ch,
	ADC_Resolution Res)
	{
		ADMUX->Data &= 0xC0;
		if ( Res == Resolution_8Bit)
		{
			ADMUX->Data |= (1<<5);
		}
		ADMUX->Data |= Ch;
		
		ADCSRA->Data |= (1<<6);
		/* Poll To Wait ADC Conv */
		while(READBIT(ADCSRA->Data,4) == 0x00){}
		/* Clear Interrupt Flag */
		SETBIT(ADCSRA->Data,4);
		
		if (Res == Resolution_8Bit)
		{
			return ADCH->Data;
		}
		else
		{
			return ((ADCL->Data)|(ADCH->Data<<8));
		}
	}
	