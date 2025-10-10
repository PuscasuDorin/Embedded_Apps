
#ifndef GPIO_H_
#define GPIO_H_

void GPIO_init(volatile uint8_t* ddr, uint8_t pin);

void GPIO_high(volatile uint8_t* port, uint8_t pin);
	
void GPIO_low(volatile uint8_t* port, uint8_t pin);

#endif /* GPIO_H_ */