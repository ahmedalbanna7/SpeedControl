/*
 * AvoMeter_Max5v.c
 *
 * Created: 9/8/2019 9:35:03 PM
 *  Author: Hamdy
 */ 


#include <AvoMeter_Max5v.h>

float32 ReadVolt(ADC_Chanel Ch , ADC_Resolution Res, float32 VoltRef)
{
	if ( Res == Resolution_8Bit)
	{
		return (ADC_Read_Polling(Ch,Resolution_8Bit) * VoltRef) / 256.0;
	}
	else
	{
		return (ADC_Read_Polling(Ch,Resolution_10Bit) * VoltRef) / 1024.0;
	}
}