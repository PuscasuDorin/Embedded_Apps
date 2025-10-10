/*
 * ADC_LEDS_App.c
 *
 * Created: 10/10/2025 8:35:01 PM
 * Author : Pusvasu Dorin-Vasile
 */ 
#include <avr/io.h>
#include "ADC.h"
#include "GPIO.h"

#define LED0_PORT PORTA
#define LED0_PIN PA0

#define LED1_PORT PORTA
#define LED1_PIN PA2

int main(void)
{
	GPIO_init(&DDRA, LED0_PIN);
	GPIO_init(&DDRA, LED1_PIN);
	ADC_init();

    while (1) 
    {
		float ADC_voltage_val = ADC_read_voltage(1, 5);
		
		if(ADC_voltage_val < 1.5){
			GPIO_high(&LED0_PORT, LED0_PIN);
			GPIO_low(&LED1_PORT, LED1_PIN);
		}
		else if(ADC_voltage_val >= 1.5){
			GPIO_low(&LED0_PORT, LED0_PIN);
			GPIO_high(&LED1_PORT, LED1_PIN);
		}
		
    }
}

