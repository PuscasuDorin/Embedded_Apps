
#ifndef UART_H_
#define UART_H_

#define F_CPU 16000000UL

void UART_Init(uint32_t baud_rate);

void UART_TransmitByte(uint8_t data);

void UART_TransmitString(char *string);

#endif /* UART_H_ */