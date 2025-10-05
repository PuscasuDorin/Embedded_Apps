/*
 * BitwiseManipulation_App[2].c
 *
 * Created: 9/2/2025 10:41:15 PM
 * Author : Puscasu Dorin-Vasile
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRL = 0xFF;
	uint8_t state = 0b11000000;
	uint8_t dir = 1;

    while (1) 
    {
		PORTL = state;
		_delay_ms(500);
		
		if(state == 0b11000000)
		{
			dir = 1;
		}
		else if(state == 0b00000011)
		{
			dir = 0;
		}
		
		if(dir)
		{
			state = state >> 1;
		}
		else if(!dir)
		{
			state = state << 1;
		}

    }
}

