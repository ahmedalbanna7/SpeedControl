/*
 * uC_Config.h
 *
 * Created: 8/6/2019 6:14:25 PM
 *  Author: Hamdy
 */ 


#ifndef UC_CONFIG_H_
#define UC_CONFIG_H_
	#define F_CPU	(16000000U)
	
	#include <STDTypes.h>
	#include <util/delay.h>
	
	
	#define _AVR_ATMEGA32A_H_INCLUDED
	/* Interrupt vectors */
	/* Vector 0 is the reset vector */
	/* External Interrupt Request 0 */
	#define INT0_vect            _VECTOR(1)
	#define INT0_vect_num        1

	/* External Interrupt Request 1 */
	#define INT1_vect            _VECTOR(2)
	#define INT1_vect_num        2

	/* External Interrupt Request 2 */
	#define INT2_vect            _VECTOR(3)
	#define INT2_vect_num        3

	/* Timer/Counter2 Compare Match */
	#define TIMER2_COMP_vect            _VECTOR(4)
	#define TIMER2_COMP_vect_num        4

	/* Timer/Counter2 Overflow */
	#define TIMER2_OVF_vect            _VECTOR(5)
	#define TIMER2_OVF_vect_num        5

	/* Timer/Counter1 Capture Event */
	#define TIMER1_CAPT_vect            _VECTOR(6)
	#define TIMER1_CAPT_vect_num        6

	/* Timer/Counter1 Compare Match A */
	#define TIMER1_COMPA_vect            _VECTOR(7)
	#define TIMER1_COMPA_vect_num        7

	/* Timer/Counter1 Compare Match B */
	#define TIMER1_COMPB_vect            _VECTOR(8)
	#define TIMER1_COMPB_vect_num        8

	/* Timer/Counter1 Overflow */
	#define TIMER1_OVF_vect            _VECTOR(9)
	#define TIMER1_OVF_vect_num        9

	/* Timer/Counter0 Compare Match */
	#define TIMER0_COMP_vect            _VECTOR(10)
	#define TIMER0_COMP_vect_num        10

	/* Timer/Counter0 Overflow */
	#define TIMER0_OVF_vect            _VECTOR(11)
	#define TIMER0_OVF_vect_num        11

	/* Serial Transfer Complete */
	#define SPI_STC_vect            _VECTOR(12)
	#define SPI_STC_vect_num        12

	/* USART, Rx Complete */
	#define USART_RXC_vect            _VECTOR(13)
	#define USART_RXC_vect_num        13

	/* USART Data Register Empty */
	#define USART_UDRE_vect            _VECTOR(14)
	#define USART_UDRE_vect_num        14

	/* USART, Tx Complete */
	#define USART_TXC_vect            _VECTOR(15)
	#define USART_TXC_vect_num        15

	/* ADC Conversion Complete */
	#define ADC_vect            _VECTOR(16)
	#define ADC_vect_num        16

	/* EEPROM Ready */
	#define EE_RDY_vect            _VECTOR(17)
	#define EE_RDY_vect_num        17

	/* Analog Comparator */
	#define ANA_COMP_vect            _VECTOR(18)
	#define ANA_COMP_vect_num        18

	/* 2-wire Serial Interface */
	#define TWI_vect            _VECTOR(19)
	#define TWI_vect_num        19

	/* Store Program Memory Ready */
	#define SPM_RDY_vect            _VECTOR(20)
	#define SPM_RDY_vect_num        20

	#define _VECTORS_SIZE 84


	/* Constants */

	#define SPM_PAGESIZE 128
	#define FLASHSTART   0x0000
	#define FLASHEND     0x7FFF
	#define RAMSTART     0x0060
	#define RAMSIZE      2048
	#define RAMEND       0x085F
	#define E2START     0
	#define E2SIZE      1024
	#define E2PAGESIZE  4
	#define E2END       0x03FF
	#define XRAMEND      RAMEND


	/* Fuses */

	#define FUSE_MEMORY_SIZE 2

	/* Low Fuse Byte */
	#define FUSE_SUT_CKSEL0  (unsigned char)~_BV(0)
	#define FUSE_SUT_CKSEL1  (unsigned char)~_BV(1)
	#define FUSE_SUT_CKSEL2  (unsigned char)~_BV(2)
	#define FUSE_SUT_CKSEL3  (unsigned char)~_BV(3)
	#define FUSE_SUT_CKSEL4  (unsigned char)~_BV(4)
	#define FUSE_SUT_CKSEL5  (unsigned char)~_BV(5)
	#define FUSE_BODEN       (unsigned char)~_BV(6)
	#define FUSE_BODLEVEL    (unsigned char)~_BV(7)

	/* High Fuse Byte */
	#define FUSE_BOOTRST     (unsigned char)~_BV(0)
	#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
	#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
	#define FUSE_EESAVE      (unsigned char)~_BV(3)
	#define FUSE_CKOPT       (unsigned char)~_BV(4)
	#define FUSE_SPIEN       (unsigned char)~_BV(5)
	#define FUSE_JTAGEN      (unsigned char)~_BV(6)
	#define FUSE_OCDEN       (unsigned char)~_BV(7)


	/* Lock Bits */
	#define __LOCK_BITS_EXIST
	#define __BOOT_LOCK_BITS_0_EXIST
	#define __BOOT_LOCK_BITS_1_EXIST


	/* Signature */
	#define SIGNATURE_0 0x1E
	#define SIGNATURE_1 0x95
	#define SIGNATURE_2 0x02

#endif /* UC_CONFIG_H_ */