#include<stm32f4xx_hal.h>

int main(){
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef sw;
	sw.Pin = GPIO_PIN_4;
	sw.Mode = GPIO_MODE_OUTPUT_PP;
	sw.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&sw);

	GPIO_InitTypeDef led;
	led.Pin = GPIO_PIN_7;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	led.Pull = GPIO_NOPULL;
	led.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB,&led);



	while(1){
		int ip = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);

		if(ip == 1){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
		}else{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
		}

	}

	return 0;
}
