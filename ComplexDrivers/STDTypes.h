/*
 * STDTypes.h
 *
 * Created: 8/6/2019 6:04:11 PM
 *  Author: Hamdy
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

	#include <stdint.h>
	
	typedef volatile uint8_t  vuint8_t;
	typedef volatile int8_t   vint8_t;
	typedef volatile uint16_t vuint16_t;
	typedef volatile int16_t  vint16_t;
	typedef volatile uint32_t vuint32_t;
	typedef volatile int32_t  vint32_t;
	typedef volatile uint64_t vuint64_t;
	typedef volatile int64_t  vint64_t;
	
	typedef float		float32;
	typedef double		float64;
	typedef long double float96;

#endif /* STDTYPES_H_ */