/*
 * UART_Transmission_App[1].c
 *
 * Created: 10/4/2025 10:41:45 PM
 * Author : Puscasu Dorin-Vasile
 */ 

#include <avr/io.h>
#include <string.h>

#define FOSC 16000000UL
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init(unsigned int ubrr)
    
	{
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);

	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
	}

void USART_Transmit( char data)
{
	while (!(UCSR0A & (1<<UDRE0)))
	;
	
	UDR0 = data;
}

int main(void)
{
	char data[] = "Hello World!\n\r";
	
	USART_Init(MYUBRR);
	
	for (int i= 0; i <= strlen(data); i++)
	{
		USART_Transmit(data[i]);	
	}
		
    while (1) 
    {
    }
}

