# ATTINY-get-vcc
ATTINY X5 Versorgungsspannung  
Ermittelt wird die Spannung VCC mithilfe der internen Referenz 1,1V:  

ADMUX = (1<<REFS1) | (0<<REFS0) | (1<<MUX3) | (1<<MUX2) | (1<<ADLAR); // intern 1.1V min 1msec  
delay(2);  
ADCSRA |= (1<<ADSC); // Start Convert  
while (bit_is_set(ADCSRA,ADSC)); // warten  
uint16_t vcc = 1100 * 254 / ADCH;    // nur high byte (fast)  

Jetzt hab ich's in eine Lib gepackt:  

Beispiel: 4,2V  
float Get_vcc_float();                        // return 4,20  
uint16_t Get_vcc_mV();                   // return 4200 0x1068  
uint16_t Get_vcc_cV();                     // return 420  0x1A4  
uint16_t Get_vcc_digi_1V1();          // return  268    0x10C  
uint16_t Get_vcc_mV_fast();           // return 4170 (nur MSB)  

Sollte ein Fehler enthalten sein - bitte melden  
