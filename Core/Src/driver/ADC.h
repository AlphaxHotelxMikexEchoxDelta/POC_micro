#include "stm32l053xx.h"

void ADC_init(ADC_TypeDef* adc, uint8_t resolution, uint8_t channel);
uint16_t ADC_read(ADC_TypeDef* adc, uint8_t channel);
