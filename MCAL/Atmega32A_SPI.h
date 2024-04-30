/*
 * Atmega32A_SPI.h
 *
 * Created: 9/17/2019 6:18:03 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_SPI_H_
#define ATMEGA32A_SPI_H_

	#include <STDTypes.h>
	#include <Common_Macros.h>
	#include <uC_Config.h>
	#include <ATmega32A_GPIO.h>
	
	

	#define SPSR	((volatile reg8 *)0x2E)
	#define SPDR	((volatile reg8 *)0x2F)
	#define	SPCR	((volatile reg8 *)0x2D)

	typedef enum
	{
		SPI_InterruptDisable=0x00,
		SPI_InterruptEnable=0x80,
	}SPI_Interrupt;
	
	typedef enum
	{
		SPI_DIS=0x00,
		SPI_ENABLE=0x40,
	}SPI_Control;
	
	typedef enum
	{
		SPI_MSBFirst=0x00,
		SPI_LSBFirst=0x20,	
	}SPI_DataOrder;
	
	typedef enum
	{
		SPI_SLaveMode=0x00,
		SPI_MasterMode=0x10,	
	}SPI_MSTR;
	
	typedef enum
	{
		SPI_FCPU_DIV4=0x0000,
		SPI_FCPU_DIV16=0x01,
		SPI_FCPU_DIV64=0x02,
		SPI_FCPU_DIV128=0x03,
		SPI_FCPU_DIV2=0x00,
		SPI_FCPU_DIV8=0x01,
		SPI_FCPU_DIV32=0x02,
	}SPI_CLOCK;
	
	typedef enum
	{
		SPI_DoubleSpeedDisable=0x00,
		SPI_DoubleSpeedEnable=0x01,
	}SPI_DoubleSpeed;
	
	
	typedef enum
	{
		SPI_Mode0=0x00,
		SPI_Mode1=0x04,
		SPI_Mode2=0x08,
		SPI_Mode3=0x0C,
	}SPI_Modes;
	
	void SPI_Init(
					SPI_CLOCK Clk,
					SPI_DoubleSpeed DoubleSpeed,
					SPI_MSTR MasterMode,
					SPI_DataOrder DataOrder,
					SPI_Interrupt State,
					SPI_Modes SMode);
					
	void SPI_Write(uint8_t Data);
	uint8_t SPI_Read(void);
	uint8_t SPI_Exchange(uint8_t Data);
	void SPI_Disable(void);
#endif /* ATMEGA32A_SPI_H_ */