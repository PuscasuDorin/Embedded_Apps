/*
 * UART_PollingMode_App[2].c
 *
 * Created: 10/10/2025 6:32:51 PM
 * Author : Dorin
 */ 

#include <avr/io.h>
#include "UART.h"


int main(void)
{
    UART_Init(9600);
	UART_TransmitString("Hello");
	
    while (1) 
    {
		uint8_t message = UART_ReceiveByte();
		UART_TransmitByte(message);
    }
}

