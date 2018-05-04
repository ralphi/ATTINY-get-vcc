#include <Arduino.h>
#include "Attinyx5_vcc.h"
#include <math.h>

// Konstruktor
Attinyx5::Attinyx5(){

}

bool Attinyx5::Set_Register(uint8_t _ADLAR){
	ADMUX = (1<<REFS1) | (0<<REFS0) | (1<<MUX3) | (1<<MUX2) | (_ADLAR << ADLAR); // intern 1.1V min 1msec
    delay(2);
    ADCSRA |= (1<<ADSC); // Start Convert
    while (bit_is_set(ADCSRA,ADSC)); // kucken wann fertig
	return true;
}

uint16_t  Attinyx5::Get_vcc_mV_fast(void){
	while(!Set_Register(0x01));
    uint16_t vcc = ( 1100L / ADCH )* 254 ;	// nur high byte
    //vcc = 1125300L / vcc;	// int 5000 = 5V
	return vcc;
}

uint16_t  Attinyx5::Get_vcc_digi_1V1(void){
	while(!Set_Register(0x00));
	uint16_t vcc = (ADCH << 8) || ADCL; 
	return vcc;
}
float  Attinyx5::Get_vcc_float(void){
	uint16_t vcc = Get_vcc_digi_1V1();
    vcc = 1.100 * 1023 / vcc;	
	return vcc;
}
uint16_t  Attinyx5::Get_vcc_mV(void){
	uint16_t vcc = Get_vcc_digi_1V1();
	vcc = (1100L  / vcc) * 1023;	
	return vcc;
}
uint16_t  Attinyx5::Get_vcc_cV(void){
	uint16_t vcc = Get_vcc_mV();
	vcc = (vcc / 10) & 0xFFF;
	return vcc;
}