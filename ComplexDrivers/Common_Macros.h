/*
 * Common_Macros.h
 *
 * Created: 8/6/2019 5:53:09 PM
 *  Author: Hamdy
 */ 


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_
	
	#define SETBIT(R,B)		((R) |=  (1<<(B)))			/* This Macros Sets a Certain Bit to 1 */
	#define CLEARBIT(R,B)	((R) &= ~(1<<(B)))			/* This Macro Clears a Certain Bit to Zero */
	#define TOGGLEBIT(R,B)	((R) ^=  (1<<(B)))			/* This Macro Toggles a Bit Value */
	#define READBIT(R,B)	(((R) &  (1<<(B))) >> (B))  /* This Macro is Used to Read A Certain Bit Value it returns 1 , 0 */


#endif /* COMMON_MACROS_H_ */