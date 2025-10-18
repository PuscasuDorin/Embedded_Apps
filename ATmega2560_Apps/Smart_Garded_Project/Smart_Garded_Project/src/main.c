/*
 * Smart_Garded_Project.c
 *
 * Created: 10/17/2025 3:11:53 PM
 * Author : Dorin
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"

int main(void)
{
    DDRG = (1<<PG5);
	PWM_init();
    while (1) 
    {
		LED_brightness(0);
		_delay_ms(500);
		LED_brightness(10);
		_delay_ms(500);
		LED_brightness(20);
		_delay_ms(500);
		LED_brightness(30);
		_delay_ms(500);
		LED_brightness(40);
		_delay_ms(500);
		LED_brightness(50);
		_delay_ms(500);
		LED_brightness(100);
		_delay_ms(500);
		LED_brightness(150);
		_delay_ms(500);
		LED_brightness(200);
		_delay_ms(500);
		LED_brightness(150);
		_delay_ms(500);
		LED_brightness(100);
		_delay_ms(500);
		LED_brightness(50);
		_delay_ms(500);
		LED_brightness(40);
		_delay_ms(500);
		LED_brightness(30);
		_delay_ms(500);
		LED_brightness(20);
		_delay_ms(500);
		LED_brightness(10);
		_delay_ms(500);
    }
}

