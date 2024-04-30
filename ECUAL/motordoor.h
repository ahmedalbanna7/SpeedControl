/*
 * motordoor.h
 *
 * Created: 4/27/2020 4:35:01 AM
 *  Author: ahmed
 */ 


#ifndef MOTORDOOR_H_
#define MOTORDOOR_H_


#include <MotorDriver_L298D.h>
#include <password.h>
#include <ATmega32A_GPIO.h>

void open_the_door (void);
void close_the_door (void);



#endif /* MOTORDOOR_H_ */