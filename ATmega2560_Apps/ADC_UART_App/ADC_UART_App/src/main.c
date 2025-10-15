/*
 * ADC_UART_App.c
 *
 * Created: 10/10/2025 11:16:19 PM
 * Author : Puscasu Dorin-Vasile
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ADC.h"
#include "UART.h"
#include <string.h>

void ADC_on(float voltage_val);

int main(void)
{
	uint8_t adc_enabled = 0;
	
	UART_Init(9600);
	ADC_init();
	
	sei();
	
	UART_TransmitString("Type 'help' to see the available commands!\n\r");
	
    while (1) 
    {
		if(str_is_complete){
			
			str_is_complete = false;

			if(strcmp(rx_buffer, "adc_on") == 0){
				UART_TransmitString("ADC is enabled!\n\r");
				adc_enabled = 1;
			}
			else if(strcmp(rx_buffer, "adc_off") == 0){
				UART_TransmitString("ADC is disabled!\n\r");
				adc_enabled = 0;
			}
			else if(strcmp(rx_buffer, "adc_status") == 0){
				if (adc_enabled){
					UART_TransmitString("ADC is ON\n\r");
				}
				else if(adc_enabled == 0){
					UART_TransmitString("ADC is OFF\n\r");
				}
			}
			else if(strcmp(rx_buffer, "help") == 0){
				UART_TransmitString("Type 'adc_on' to enable ADC\n\r");
				UART_TransmitString("Type 'adc_off' to disable ADC\n\r");
				UART_TransmitString("Type 'adc_status' to see the current ADC status\n\r");
			}
		}
		else if(adc_enabled){
			float ADC_voltage_val = ADC_read_voltage(1, 5);
			
			ADC_on(ADC_voltage_val);
			
			_delay_ms(1000);
		}
		
    }
}

void ADC_on(float voltage_val){
	
	if(voltage_val < 1.5){
		UART_TransmitString("Voltage is LOW\n\r");
	}
	else if(voltage_val >= 1.5 && voltage_val < 3.5){
		UART_TransmitString("Voltage is NORMAL\n\r");
	}
	else if(voltage_val >= 3.5){
		UART_TransmitString("Voltage is HIGH\n\r");
	}
}