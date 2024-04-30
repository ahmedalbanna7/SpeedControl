/*
 * Atmega32A_USART.h
 *
 * Created: 9/16/2019 7:42:40 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_USART_H_
#define ATMEGA32A_USART_H_

	#include <uC_Config.h>
	#include <STDTypes.h>
	#include <Common_Macros.h>
	#include <ATmega32A_GPIO.h>
	
	
	#define UDR		((volatile reg8 *)0x2C)
	#define UCSRA	((volatile reg8 *)0x2B)
	#define UCSRB	((volatile reg8 *)0x2A)
	#define UCSRC	((volatile reg8 *)0x40)
	#define UBRRL	((volatile reg8 *)0x29)
	#define UBRRH	((volatile reg8 *)0x40)
	

	#define IS_USART_Rx_Msg			((UCSRA->Bits.B7))
	#define IS_USART_TxShiftReg		((UCSRA->Bits.B6))
	#define IS_USART_TX_RegEmpty	((UCSRA->Bits.B5))
	
	#define IS_USART_FrameErorr		((UCSRA->Bits.B4))
	#define IS_USART_DataOverError	((UCSRA->Bits.B3))
	#define IS_USART_ParityError	((UCSRA->Bits.B2))
	
	typedef enum
	{
		UART_NormalSpeed,
		UART_DoubleSpeed,
		USRT_Sync,
	}USART_ClockMode;
	
	typedef enum
	{
		SingleProcessor_Mode,
		Multiprocessor_Mode,	
	}USART_WorkMode;
	
	typedef enum
	{
		USART_Interrupt_Disable=0x00,
		USART_TX_InterruptEnable=0x40,
		USART_RX_InterruptEnable=0x80,
		USART_DR_InterruptEnable=0x20,
		USART_TX_RX_InterruptEnable=0xc0,
		USART_TX_DR_InterruptEnable=0x60,
		USART_RX_DR_InterruptEnable=0xA0,
		USART_TX_RX_DR_InterruptEnable=0xE0,
	}USART_Interrupts;
	
	typedef enum
	{
		USART_DISABLE=0x00,
		USART_TX_Only=0x08,
		USART_RX_Only=0x10,
		USART_TX_RX_Enable=0x18,
	}USART_Enable;
	
	typedef enum
	{
		USART_ParityDisabled_1Stop=0x00,
		USART_ParityDisabled_2Stop=0x08,
		USART_EvenParity_1Stop=0x20,
		USART_EvenParity_2Stop=0x28,
		USART_OddParity_1Stop=0x30,
		USART_OddParity_2Stop=0x38,
	}USART_ControlFrame;
	typedef enum
	{
		USART_5BitData=0x00,
		USART_6BitData=0x02,
		USART_7BitData=0x04,
		USART_8BitData=0x06,
		USART_9BitData=0x0406,
	}USART_DataFrame;
	
	void USART_Init(
					USART_Enable		En,
					USART_ClockMode		Clk,
					float32			BaudRate,
					USART_WorkMode		WMode,
					USART_Interrupts	Interrupt,
					USART_ControlFrame	CFrame,
					USART_DataFrame		DFrame);
	uint8_t USART_ReadByte(void);
	void	USART_WriteByte(uint8_t Data);
#endif /* ATMEGA32A_USART_H_ */