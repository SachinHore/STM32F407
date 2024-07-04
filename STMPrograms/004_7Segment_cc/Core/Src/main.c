#include<stm32f4xx_hal.h>
/*
void all_reset(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_1 |GPIO_PIN_2 | GPIO_PIN_3 |GPIO_PIN_4 | GPIO_PIN_5 |GPIO_PIN_6, 0);
}

void send_zero(){
	all_reset();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_1 |GPIO_PIN_2 | GPIO_PIN_3 |GPIO_PIN_4 | GPIO_PIN_5, 1);
}

void send_one(){
	all_reset();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2, 1);
}
*/

int main(){
	int arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef segment;

	segment.Pin = GPIO_PIN_0 | GPIO_PIN_1 |GPIO_PIN_2 | GPIO_PIN_3 |GPIO_PIN_4 | GPIO_PIN_5 |GPIO_PIN_6;
	segment.Mode = GPIO_MODE_OUTPUT_PP;
	segment.Pull = GPIO_NOPULL;
	segment.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA,&segment);


	while(1){
		/*
		send_zero();
		HAL_Delay(1000);
		send_one();
		HAL_Delay(1000);
		*/
		/*
		GPIOA->ODR = 0x3f;
		HAL_Delay(1000);
		GPIOA->ODR = 0x06;
		HAL_Delay(1000);
		*/

		for(int i = 0; i < 10; i++){
			GPIOA->ODR = arr[i];
			HAL_Delay(1000);
		}


	}

	return 0;
}
