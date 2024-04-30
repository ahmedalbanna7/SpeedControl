/*
 * password.h
 *
 * Created: 4/27/2020 1:21:46 AM
 *  Author: ahmed
 */ 


#ifndef PASSWORD_H_
#define PASSWORD_H_

#include <LCD.h>
#include <Keypad.h>
#include <ATmega32a_ADC.h>
#include <EEPROM.h>
#include <motordoor.h>
#include <Atmega32A_Interrupt.h>

#define  PASSWORD_LENGTH	 10
#define  DEBUG				 0
#define  SETUP				 0
#define  NUM_OF_TRIALS_ADDR  25
static char str[100] = {0};


void initpass (void);
void welcome_message (void);
void choose_list (void);
void choose_listsecond(void);
void sign_up (void);
void log_in (void);
void change_password(void);
unsigned char get_password(unsigned char* pass);
unsigned char check_password(unsigned char len, unsigned char* password);
unsigned char get_puk_code(void);
unsigned char compare(unsigned char*, unsigned char*, unsigned char, unsigned char);
void try_again (void);
unsigned char is_door_is_permanently_closed(void);
void fooww(void);


#endif /* PASSWORD_H_ */