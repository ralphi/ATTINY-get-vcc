/*
	Attinyx5_vcc.h
*/
#ifndef	ATTINYX5_VCC_H
#define	ATTINYX5_VCC_H

#include <Arduino.h>
#include <math.h>

class Attinyx5
{
	public:
		Attinyx5();
		float Get_vcc_float();
		uint16_t Get_vcc_mV();
		uint16_t Get_vcc_cV();
		uint16_t Get_vcc_digi_1V1();
		uint16_t Get_vcc_mV_fast();
		
	private:

		bool Set_Register(uint8_t _ADLAR);
};
#endif
// Ende