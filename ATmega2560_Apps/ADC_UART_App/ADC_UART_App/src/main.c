/*
 * ADC_UART_App.c
 *
 * Created: 10/10/2025 11:16:19 PM
 * Author : Puscasu Dorin-Vasile
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "UART.h"

int main(void)
{
	UART_Init(9600);
	ADC_init();
	
    while (1) 
    {
		float ADC_voltage_val = ADC_read_voltage(0, 5);
		
		if(ADC_voltage_val < 1.5){
			UART_TransmitString("Voltage is LOW\n\r");
		}
		else if(ADC_voltage_val >= 1.5 && ADC_voltage_val < 3.5){
			UART_TransmitString("Voltage is NORMAL\n\r");
		}
		else if(ADC_voltage_val >= 3.5){
			UART_TransmitString("Voltage is HIGH\n\r");
		}
		
		_delay_ms(1000);
    }
}

