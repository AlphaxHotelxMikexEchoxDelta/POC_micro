
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "driver/rgb.h"
#include "driver/ADC.h"
#include "driver/led.h"
#include "stm32l053xx.h"


void SystemClock_Config(void);

RGB_TypeDef bleu;
RGB_TypeDef rouge;
RGB_TypeDef vert;

int LUMOS; //Reference du film 'Harry potter'
int MOUAHAHAHAHA;

int is_light_up(int light){
	if( light <= 1000 ){ return 1 ; }
	else{ return 0 ; }
}

int is_Babord(int hihihihi){
	if( hihihihi >= 1000 ){ return 1 ; }
	else{ return 0 ; }
}

void Alumm_la_lumiere_ya_zbi( int LUMOS, int MOUAHAHAHAHA ){

	if ( is_Babord(MOUAHAHAHAHA) && !is_light_up(LUMOS)) {
		Rgb_turnOn(&rouge);
		Rgb_turnOff(&vert);
		Rgb_turnOff(&bleu);
	}
	else if ( !is_Babord(MOUAHAHAHAHA) && is_light_up(LUMOS) ) {
		Rgb_turnOff(&rouge);
		Rgb_turnOn(&vert);
		Rgb_turnOff(&bleu);
	}
	else if ( !is_Babord(MOUAHAHAHAHA) && !is_light_up(LUMOS) ) {
		Rgb_turnOff(&rouge);
		Rgb_turnOff(&vert);
		Rgb_turnOn(&bleu);
	}

}


int main(void)
{

	//*******************************************************//
	  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
	  SystemClock_Config();
	  MX_GPIO_Init();
	  MX_USART2_UART_Init();
	//*******************************************************//

	// Initialisations  des leds (suivre le schema pour que cela fonctionne !!)
	  Rgb_init(&rouge, GPIOB, 0); // 1 Rouge	PB0 (A3)
	  Rgb_init(&bleu, GPIOC, 0);  // 3 Bleu		PC1 (A4)
	  Rgb_init(&vert, GPIOC, 1);  // 4 Vert		PC2	(A5)

	  ADC_init(ADC1, 12, 0);


	// Okaayyyy let's gooooow...
	  while(1){

		  LUMOS = ADC_read(ADC1, 0);
		  MOUAHAHAHAHA = ADC_read(ADC1, 1);
		  Alumm_la_lumiere_ya_zbi(LUMOS, MOUAHAHAHAHA);

	  }
}


//**********************************************************************************//
//******************************** pas pour nous ça ********************************//
//**********************************************************************************//
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);






  while (LL_PWR_IsActiveFlag_VOS() != 0)
  {
  }
  LL_RCC_HSI_Enable();

  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }

  LL_Init1msTick(16000000);

  LL_SetSystemCoreClock(16000000);
  LL_RCC_SetUSARTClockSource(LL_RCC_USART2_CLKSOURCE_PCLK1);
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
