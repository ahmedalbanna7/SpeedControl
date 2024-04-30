/*
 * AvoMeter_Max5v.h
 *
 * Created: 9/8/2019 9:35:12 PM
 *  Author: Hamdy
 */ 


#ifndef AVOMETER_MAX5V_H_
#define AVOMETER_MAX5V_H_

	#include <ATmega32a_ADC.h>
	
	
	float32 ReadVolt(ADC_Chanel Ch , ADC_Resolution Res, float32 VoltRef);

#endif /* AVOMETER_MAX5V_H_ */