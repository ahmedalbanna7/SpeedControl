/*
 * Lm35.c
 *
 * Created: 9/8/2019 9:34:33 PM
 *  Author: Hamdy
 */ 


#include <Lm35.h>


	float32 LM35_TempRead(ADC_Chanel Ch , ADC_Resolution Res, float32 Vref)
	{
		if (Res == Resolution_8Bit)
		{
			return ((Vref * ADC_Read_Polling(Ch,Resolution_8Bit) * 100)/256.0);
		}
		else
		{
			return ((Vref * (float32)ADC_Read_Polling(Ch,Resolution_10Bit) * 100)/1024.0);
		}
	}