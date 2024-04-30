/*
 * motordoor.c
 *
 * Created: 4/27/2020 4:35:25 AM
 *  Author: ahmed
 */ 
 #include <motordoor.h>

 void open_the_door (void)
 {
		 GPIO_OutputHandle(GPIOD,PIN3,HIGH);
	 	 GPIO_OutputHandle(GPIOD,PIN4,LOW);

 LCD_Clear();
 LCD_DisplayStringrowcol(" The door is opened",0,6);
 _delay_ms(2000);
 eeprom_write(NUM_OF_TRIALS_ADDR,0);
  GPIO_OutputHandle(GPIOD,PIN3,LOW);
  GPIO_OutputHandle(GPIOD,PIN4,HIGH);
   _delay_ms(2000);
   GPIO_OutputHandle(GPIOD,PIN4,LOW);
 }
 void close_the_door (void)
 {
  GPIO_OutputHandle(GPIOD,PIN3,LOW);
  GPIO_OutputHandle(GPIOD,PIN4,HIGH);
 LCD_Clear();
 LCD_DisplayStringrowcol(" The door is Close",0,6);
 _delay_ms(2000);
 eeprom_write(NUM_OF_TRIALS_ADDR,0);
 }
