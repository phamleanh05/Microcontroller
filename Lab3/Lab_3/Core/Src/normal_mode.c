#include "main.h"
#include "normal_mode.h"
int state = 0;
int led[3] = {0,0,0};
int horizontal = 0;
int vertical = 0;

void normal_mode(void){
	switch(state){
		case 0:
			HAL_GPIO_WritePin(GPIOA,LED_RED1_Pin|LED_YELLOW1_Pin|LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA,LED_GREEN_Pin|LED_YELLOW_Pin|LED_RED_Pin, GPIO_PIN_SET);
			break;
		case 1:
			horizontal--;
			vertical--;
			updateClockBuffer(horizontal, vertical);
			HAL_GPIO_WritePin(GPIOA,LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA,LED_YELLOW1_Pin|LED_GREEN1_Pin, GPIO_PIN_SET);
			if(horizontal - led[3] >= 0){
				HAL_GPIO_WritePin(GPIOA,LED_GREEN_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,LED_YELLOW_Pin|LED_RED_Pin, GPIO_PIN_SET);
			}
			else{
				HAL_GPIO_WritePin(GPIOA,LED_YELLOW_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,LED_GREEN_Pin|LED_RED_Pin, GPIO_PIN_SET);
			}


			if(horizontal == 0) {
				state = 2;
			     horizontal = led[2];
			     vertical = led[1];
			     break;
			}
			if(vertical == 0) {
				vertical = led[3];
			}

			break;
		case 2:
			horizontal--;
			vertical--;
			updateClockBuffer(horizontal, vertical);
			HAL_GPIO_WritePin(GPIOA,LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA,LED_YELLOW_Pin|LED_GREEN_Pin, GPIO_PIN_SET);
			if(vertical - led[3] >= 0){
				HAL_GPIO_WriteledPin(GPIOA,LED_GREEN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,LED_YELLOW1_Pin|LED_RED1_Pin, GPIO_PIN_SET);
			}
			if (horizontal == 0){
				state = 3;
				horizontal = led[3];
				break;
			}

			break;
		case 3:
			vertical--;
			horizontal--;
			updateClockBuffer(horizontal, vertical);
			HAL_GPIO_WritePin(GPIOA,LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA,LED_YELLOW_Pin|LED_GREEN_Pin, GPIO_PIN_SET);
			if(horizontal >= 0){
				HAL_GPIO_WritePin(GPIOA,LED_YELLOW1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,LED_GREEN1_Pin|LED_RED1_Pin, GPIO_PIN_SET);
			}
			if (horizontal == 0){
				state = 1;
				horizontal = led[1];
				vertical = led[2];
				break;
			}

			break;
		default:
			break;
	}

}



