/*
 * UART_PollingMode_App[2].c
 *
 * Created: 10/10/2025 6:32:51 PM
 * Author : Dorin
 */ 

#include <avr/io.h>
#include "UART.h"
#include <avr/interrupt.h>

ISR(USART0_RX_vect);

int main(void)
{
    UART_Init(9600);
	UART_TransmitString("Hello Siemens");
	
	UCSR0B |= (1 << RXCIE0);
	sei();
	
    while (1) 
    {
		//For Polling Mode
		//uint8_t message = UART_ReceiveByte();
		//UART_TransmitByte(message);
    }
}

ISR(USART0_RX_vect)
{
	uint8_t message = UDR0;
	UART_TransmitByte(message);
}