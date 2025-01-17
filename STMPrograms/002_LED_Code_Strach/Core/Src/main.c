#include<stm32f4xx_hal.h>

int main(){
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef led;

	led.Pin = GPIO_PIN_10 | GPIO_PIN_7;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	led.Pull = GPIO_NOPULL;
	led.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOA,&led);
	HAL_GPIO_Init(GPIOB,&led);

	while(1){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);
		HAL_Delay(1000);
	}

	return 0;
}
