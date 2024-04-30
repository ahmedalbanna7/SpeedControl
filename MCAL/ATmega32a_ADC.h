/*
 * ATmega32a_ADC.h
 *
 * Created: 9/8/2019 8:23:30 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_ADC_H_
#define ATMEGA32A_ADC_H_

	#include <ATmega32A_GPIO.h>
	#include <uC_Config.h>
	#include <STDTypes.h>
	#include <Common_Macros.h>
	
	#define ADMUX	((volatile reg8 *)(0x27))
	#define ADCSRA	((volatile reg8 *)(0x26))
	#define SFIOR	((volatile reg8 *)(0x50))
	#define ADCL	((volatile reg8 *)(0x24))
	#define ADCH	((volatile reg8 *)(0x25))


	typedef enum
	{
		AREF_Refernce=0x00,
		AVCC_Refernce=0x40,
		_2_56V_Refernce=0xC0,
	}ADC_RefernceVolt;
	
	typedef enum
	{
		Resolution_8Bit=0x20,
		Resolution_10Bit=0x00,
	}ADC_Resolution;
	
	typedef enum
	{
		ADC0,
		ADC1,
		ADC2,
		ADC3,
		ADC4,
		ADC5,
		ADC6,
		ADC7,
		DIFF_PADC0_NADC0_G10,
		DIFF_PADC1_NADC0_G10,
		DIFF_PADC0_NADC0_G200,
	}ADC_Chanel;
	
	
	typedef enum
	{
		ADC_Dis=0x00,
		ADC_Enable=0x80,
	}ADC_Control;
	
	typedef enum
	{
		ADC_Polling=0x00,
		ADC_Interrupt_Enable=0x08,
	}ADC_WorkMode;
	
	typedef enum
	{
		ADC_SingleConv=0x00,
		ADC_AutoTrig=0x20,
	}ADC_ConvMode;
	
	
	typedef enum
	{
		ADC_Prescale_2=0x01,
		ADC_Prescale_4,
		ADC_Prescale_8,
		ADC_Prescale_16,
		ADC_Prescale_32,
		ADC_Prescale_64,
		ADC_Prescale_128,
	}ADC_PreScale;
	
	
	void ADC_Init(
				  ADC_RefernceVolt Ref,
				  ADC_WorkMode Int_Mode,
				  ADC_ConvMode ConvMode,
				  ADC_PreScale Freq_PreScale);
	
	void ADC_Disable(void);
	uint16_t ADC_Read_Polling(
						ADC_Chanel Ch,
						ADC_Resolution Res);
	
#endif /* ATMEGA32A_ADC_H_ */