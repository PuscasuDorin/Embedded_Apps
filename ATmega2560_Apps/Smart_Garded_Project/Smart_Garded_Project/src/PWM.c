#include <avr/io.h>
#include "PWM.h"

void PWM_init (void){
	TCCR0A = (1<<COM0B1) | (1<<WGM01) | (1<<WGM00); //COM->Non-Inverting Mode and WGM->fast PWM Mode
	
	TCCR0B = (1<<CS01); //CS->Clock Prescaler(clk/8)
}

void LED_brightness(uint8_t brightness){
	if (brightness == 0 ){
		TCCR0A &= ~(1<<COM0B1);
		PORTG &= (0<<PG5);
	}
	else{
	TCCR0A |= (1<<COM0B1);
	OCR0B = brightness;
	}
}