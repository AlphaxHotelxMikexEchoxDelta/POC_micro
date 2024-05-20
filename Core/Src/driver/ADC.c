#include "ADC.h"

void ADC_init(ADC_TypeDef* adc, uint8_t resolution, uint8_t channel) {
    // Active l’horloge pour l'ADC
    RCC->APB2ENR |= (1<<9);

    // Désactivation de l'ADC, s'il est activé
    if((adc->CR & ADC_CR_ADEN) != 0) {
        adc->CR &= ~ADC_CR_ADEN;
        while((adc->CR & ADC_CR_ADEN) != 0); // Wait for ADC to be fully disabled
    }

    // Activation de la calibration
    adc->CR |= ADC_CR_ADCAL;

    // Attente de la fin de la calibration (ADCAL == 0)
    while((adc->CR & ADC_CR_ADCAL) != 0);

    // Configuration le mode de conversion en continue (si nécessaire)
    adc->CFGR1 |= (1 << ADC_CFGR1_CONT_Pos); // Remove if not needed

    // Configuration de la résolution de conversion
    adc->CFGR1 &= ~(0b11 << ADC_CFGR1_RES_Pos);
    switch(resolution) {
        case 12:
            adc->CFGR1 &= ~(0b11 << ADC_CFGR1_RES_Pos);
            break;
        case 10:
            adc->CFGR1 |= (0b01 << ADC_CFGR1_RES_Pos);
            break;
        case 8:
            adc->CFGR1 |= (0b10 << ADC_CFGR1_RES_Pos);
            break;
        case 6:
            adc->CFGR1 |= (0b11 << ADC_CFGR1_RES_Pos);
            break;
        default:
            adc->CFGR1 &= ~(0b00 << ADC_CFGR1_RES_Pos);
            break;
    }

    // Sélection du channel à convertir
    adc->CHSELR = (1 << channel);

    // Activation de l'ADC
    adc->CR |= (1 << ADC_CR_ADEN_Pos);
    while(!(adc->ISR & ADC_ISR_ADRDY)); // Wait for ADC to be ready

    // Démarrage de la conversion
    adc->CR |= (1 << ADC_CR_ADSTART_Pos);
}

uint16_t ADC_read(ADC_TypeDef* adc, uint8_t channel) {
    // Sélection du channel à convertir
    adc->CHSELR = 1 << channel;

    // Démarrage de la conversion
    adc->CR |= (1 << ADC_CR_ADSTART_Pos);

    // Attente de la fin de la conversion (EOC)
    while ((adc->ISR & ADC_ISR_EOC) == 0);

    // Lecture de la valeur convertie depuis DR
    uint16_t value = adc->DR;

    return value;
}
