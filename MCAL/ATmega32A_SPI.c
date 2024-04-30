/*
 * ATmega32A_SPI.c
 *
 * Created: 9/17/2019 6:18:19 PM
 *  Author: Hamdy
 */ 


#include <Atmega32A_SPI.h>


void SPI_Init(
				SPI_CLOCK Clk,
				SPI_DoubleSpeed DoubleSpeed,
				SPI_MSTR MasterMode,
				SPI_DataOrder DataOrder,
				SPI_Interrupt State,
				SPI_Modes SMode)
{
	SPSR->Data = DoubleSpeed;
	SPCR->Data = Clk | MasterMode | DataOrder | State | SMode | SPI_ENABLE; 
	if ( MasterMode == SPI_MasterMode)
	{
		GPIO_OutputHandle(GPIOB,PIN4,HIGH);
		GPIO_DirectionSet(GPIOB,PIN4,OUTPUT);
		GPIO_DirectionSet(GPIOB,PIN5,OUTPUT);
		GPIO_DirectionSet(GPIOB,PIN6,OUTPUT);
		GPIO_DirectionSet(GPIOB,PIN7,OUTPUT);
		
	}
		if ( MasterMode == SPI_SLaveMode)

	{
		GPIO_DirectionSet(GPIOB,PIN4,INPUT_FLOAT);
		GPIO_DirectionSet(GPIOB,PIN4,INPUT_FLOAT);
		GPIO_DirectionSet(GPIOB,PIN5,INPUT_FLOAT);
		GPIO_DirectionSet(GPIOB,PIN6,OUTPUT);
		GPIO_DirectionSet(GPIOB,PIN7,INPUT_FLOAT);
	}

}

void SPI_Write(uint8_t Data)
{
	SPDR->Data = Data;
	while(SPSR->Bits.B7 == 0){}
	
}

uint8_t SPI_Readslave(void)
{
	while(SPSR->Bits.B7 == 0){}
	return SPDR->Data;
}
uint8_t SPI_Exchange(uint8_t Data)
{
	SPI_Write(Data);
	return SPI_Read();
}
void SPI_Disable(void)
{
	SPCR->Data = SPI_DIS;
}




