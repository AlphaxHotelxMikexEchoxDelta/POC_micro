
#include "stm32l053xx.h"

typedef struct {
	GPIO_TypeDef* gpioPort;
	uint8_t pin;
} RGB_TypeDef;

void Rgb_init(RGB_TypeDef* rgb, GPIO_TypeDef* port, uint8_t pin);
uint8_t Rgb_isOn(RGB_TypeDef* rgb);
uint8_t Rgb_isOff(RGB_TypeDef* rgb);
void Rgb_turnOn(RGB_TypeDef* rgb);
void Rgb_turnOff(RGB_TypeDef* rgb);
