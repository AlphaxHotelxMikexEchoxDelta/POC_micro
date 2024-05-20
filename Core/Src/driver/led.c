// led.c

#include "led.h"

void Led_init(LED_TypeDef *led, GPIO_TypeDef *port, uint8_t pn) {
    led->gpioPort = port;
    led->pin = pn;

    // Activation de l'horloge sur le port en question
    uint8_t nb_port = ((uint32_t)port - IOPPERIPH_BASE) / 0x400;
    RCC->IOPENR |= (1 << nb_port);

    // Configuration de la pin en sortie
    led->gpioPort->MODER &= ~(0b11 << (2 * pn));
    led->gpioPort->MODER |= (0b01 << (2 * pn));
}

void Led_turnOn(LED_TypeDef *led) {
    led->gpioPort->ODR |= (1 << led->pin);
}

void Led_turnOff(LED_TypeDef *led) {
    led->gpioPort->ODR &= ~(1 << led->pin);
}

void Led_toggle(LED_TypeDef *led) {
    led->gpioPort->ODR ^= (1 << led->pin);
}

uint8_t Led_isOn(LED_TypeDef *led) {
    return (led->gpioPort->ODR & (1 << led->pin)) ? 1 : 0;
}

uint8_t Led_isOff(LED_TypeDef *led) {
    return !Led_isOn(led);
}
