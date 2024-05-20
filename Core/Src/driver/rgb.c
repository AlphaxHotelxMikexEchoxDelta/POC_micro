
#include "stm32l053xx.h"
#include "rgb.h"

void Rgb_init(RGB_TypeDef* rgb, GPIO_TypeDef* port, uint8_t pin){

	rgb->gpioPort = port;
	rgb->pin = pin;

	uint8_t nb_port;
	nb_port = (uint32_t)((uint32_t*)port - IOPPERIPH_BASE) / (uint32_t)0x400;

	RCC->IOPENR |= 1<<nb_port;

	rgb->gpioPort->MODER &= ~(0b11<<2*pin);
	rgb->gpioPort->MODER |= (0b01<<2*pin);

}


uint8_t Rgb_isOn(RGB_TypeDef* rgb){
	if((rgb->gpioPort->ODR & (1<<rgb->pin))>0){
		return 1;
	}
	else{
		return 0;
	}
}

uint8_t Rgb_isOff(RGB_TypeDef* rgb){
	return !Rgb_isOn(rgb);
}

void Rgb_turnOn(RGB_TypeDef* rgb){
	rgb->gpioPort->ODR |= (1<<rgb->pin);
}

void Rgb_turnOff(RGB_TypeDef* rgb){
	rgb->gpioPort->ODR &= ~(1<<rgb->pin);
}





