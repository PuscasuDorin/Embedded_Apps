/*
 * UART_Transmission_App[1].c
 *
 * Created: 10/4/2025 10:41:45 PM
 * Author : Puscasu Dorin-Vasile
 */ 

#include <avr/io.h>
#include <string.h>
#include "UART.h"

int main(void)
{
	UART_Init(9600);
	
	UART_TransmitString("Embedded Systems Course\r\n");	
	
    while (1) 
    {
    }
}

