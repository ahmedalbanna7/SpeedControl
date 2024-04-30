/*
 * Lm35.h
 *
 * Created: 9/8/2019 9:34:26 PM
 *  Author: Hamdy
 */ 


#ifndef LM35_H_
#define LM35_H_

	#include <uC_Config.h>
	#include <STDTypes.h>
	#include <ATmega32a_ADC.h>
	#include <AvoMeter_Max5v.h>
	
	float32 LM35_TempRead(ADC_Chanel Ch , ADC_Resolution Res, float32 Vref);



#endif /* LM35_H_ */