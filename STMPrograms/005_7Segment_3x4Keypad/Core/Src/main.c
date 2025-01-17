#include<stm32f4xx_hal.h>


int main(){
	int arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef segment;
	segment.Pin = GPIO_PIN_0 | GPIO_PIN_1 |GPIO_PIN_2 | GPIO_PIN_3 |GPIO_PIN_4 | GPIO_PIN_5 |GPIO_PIN_6;
	segment.Mode = GPIO_MODE_OUTPUT_PP;
	segment.Pull = GPIO_NOPULL;
	segment.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA,&segment);

	GPIO_InitTypeDef row;
	row.Pin = GPIO_PIN_0 | GPIO_PIN_1 |GPIO_PIN_2 | GPIO_PIN_3 ;
	row.Mode = GPIO_MODE_OUTPUT_PP;
	row.Pull = GPIO_NOPULL;
	row.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB,&row);

	GPIO_InitTypeDef col;
	col.Pin = GPIO_PIN_4 | GPIO_PIN_5 |GPIO_PIN_6;
	col.Mode = GPIO_MODE_INPUT;
	col.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB,&col);



	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 |GPIO_PIN_2 | GPIO_PIN_3, 1);
	while(1){

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 , 0);
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)==0){
				GPIOA->ODR = arr[1];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)==0){
				GPIOA->ODR = arr[2];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)==0){
				GPIOA->ODR = arr[3];
				HAL_Delay(200);
			}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 , 1);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1 , 0);
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)==0){
				GPIOA->ODR = arr[4];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)==0){
				GPIOA->ODR = arr[5];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)==0){
				GPIOA->ODR = arr[6];
				HAL_Delay(200);
			}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1 , 1);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2 , 0);
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)==0){
				GPIOA->ODR = arr[7];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)==0){
				GPIOA->ODR = arr[8];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)==0){
				GPIOA->ODR = arr[9];
				HAL_Delay(200);
			}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2 , 1);

			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3 , 0);
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)==0){
				//GPIOA->ODR = arr[1];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)==0){
				GPIOA->ODR = arr[0];
				HAL_Delay(200);
			}
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)==0){
				//GPIOA->ODR = arr[3];
				HAL_Delay(200);
			}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3 , 1);

	}

	return 0;
}
