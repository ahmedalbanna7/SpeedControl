/*
 * Atmega32A_USART.c
 *
 * Created: 9/16/2019 7:42:31 PM
 *  Author: Hamdy
 */ 

#include <Atmega32A_USART.h>

	void USART_Init(
					USART_Enable		En,
					USART_ClockMode		Clk,
					float32			BaudRate,
					USART_WorkMode		WMode,
					USART_Interrupts	USART_Interrupt,
					USART_ControlFrame	CFrame,
					USART_DataFrame		DFrame)
{
		uint16_t Temp_BaudRate=0;
		UCSRA->Data =WMode;
		UCSRB->Data = USART_Interrupt | En ;
		if(DFrame == USART_9BitData)
		{
			UCSRB->Bits.B2=1;
		}
		
		
		UCSRC->Data = (1<<7) | 	CFrame | DFrame;
		if(Clk == USRT_Sync)
		{
			UCSRC->Data |= (1<<7) | (1<<6);
					Temp_BaudRate = (F_CPU / (2.0*BaudRate)) - 0.5;
			
		}	
		if (Clk == UART_DoubleSpeed)
		{
					UCSRA->Bits.B1=1;
					Temp_BaudRate = (F_CPU / (8.0*BaudRate)) - 0.5;
		}
		else if (Clk == UART_NormalSpeed)
		{
					Temp_BaudRate = (F_CPU / (16.0*BaudRate)) - 0.5;
		}
		
		UBRRL->Data= (Temp_BaudRate) ;
		UBRRH->Data= (Temp_BaudRate>>8);
}

	uint8_t USART_ReadByte(void)
	{
			if (IS_USART_DataOverError || IS_USART_FrameErorr || IS_USART_ParityError)
			{
				// Error Handling Code
			}
			
			while(! IS_USART_Rx_Msg){}
				return UDR->Data;		
	}
	void	USART_WriteByte(uint8_t Data)
	{
			while(!IS_USART_TX_RegEmpty){}
			UDR->Data =Data; 
	}
	