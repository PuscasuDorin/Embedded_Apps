/*
 * External_Interrupt_App[2].c
 *
 * Created: 9/23/2025 4:10:14 PM
 * Author : Puscasu Dorin-Vasile
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_MASK ((1 << PA0) | (1 << PA2) | (1 << PA4) | (1 << PA6))

//Functions
void interrupt_buttons_init(void);
void lights_init (void);
void lights_on (void);
void lights_off (void);

int main(void)
{
	interrupt_buttons_init();
    lights_init();
	lights_on();
	sei();
	
    while (1) 
    {
    }
}

void lights_init(void){
	DDRA |= LED_MASK; 
}

void lights_on(void){
	PORTA |= LED_MASK;
}

void lights_off(void){
	PORTA &= ~LED_MASK;
}

void interrupt_buttons_init(void){
	DDRD &= ~((1<<PD0) | (1<<PD1));
	PORTD |= (1<<PD0) | (1<<PD1);
	EIMSK |= (1<<INT0) | (1<<INT1);
	EICRA |= (1<<ISC01)	| (1<<ISC11);	 
}

ISR(INT0_vect){
	lights_on();
}

ISR(INT1_vect){
	lights_off();
}