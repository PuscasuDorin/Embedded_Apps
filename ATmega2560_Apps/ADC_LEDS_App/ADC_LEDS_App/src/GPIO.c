 
#include <avr/io.h>
#include "GPIO.h"

void GPIO_init(volatile uint8_t *ddr, uint8_t pin){
	
	*ddr |= (1 << pin);
}

void GPIO_high(volatile uint8_t *port, uint8_t pin){
	
	*port |= (1<<pin);
}

void GPIO_low(volatile uint8_t *port, uint8_t pin){
	
	*port &= ~(1<<pin);
}