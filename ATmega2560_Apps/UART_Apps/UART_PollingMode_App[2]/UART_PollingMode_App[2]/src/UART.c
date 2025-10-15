#include <avr/io.h>
#include <UART.h>


void UART_Init(uint32_t baud_rate){
	uint16_t ubrr = (F_CPU / (16 * baud_rate) -1);
	
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)(ubrr);
	
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);

	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
}

void UART_TransmitByte(uint8_t data){
	while (!(UCSR0A & (1<<UDRE0)));
	 
	UDR0 = data;
}

void UART_TransmitString(char *string){
	while(*string){
		UART_TransmitByte(*string++);
	}
}

uint8_t UART_ReceiveByte(void){
	while (!(UCSR0A & (1<<RXC0)));
	
	return UDR0;
}