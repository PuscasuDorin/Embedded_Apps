/*
 * ADC_UART_App.c
 *
 * Created: 10/10/2025 11:16:19 PM
 * Author : Puscasu Dorin-Vasile
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "UART.h"

int main(void)
{
	UART_Init(9600);
	ADC_init();
	
    while (1) 
    {
    }
}

