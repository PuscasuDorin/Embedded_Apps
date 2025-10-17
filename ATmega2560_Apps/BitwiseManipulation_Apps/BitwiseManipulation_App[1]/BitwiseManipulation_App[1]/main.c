/*
 * BitwiseManipulation_App[1].c
 *
 * Created: 8/26/2025 10:50:55 AM
 * Author : Puscasu Dorin-Vasile
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRL = 0xFF;

    while (1) 
    {
		//V1
		/*
		PORTL = (1 << PL0) | (1<<PL2) | (1<<PL4) | (1<<PL6);
		_delay_ms(400);
		PORTL = (1 << PL1) | (1<<PL3) | (1<<PL5) | (1<<PL7);
		_delay_ms(400);
		*/
		
		//V2
		PORTL = 0xAA;
		_delay_ms(400);
		PORTL = 0x55;
		_delay_ms(400);
    }
}

