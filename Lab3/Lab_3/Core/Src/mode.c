#include <mode.h>
#include "main.h"
#include "input_reading.h"
#include "normal_mode.h"


int mode = 0;
const int NO_OF_MODES = 4;

void mode(int mode){
	switch ( mode ){
		case 0 :
			normal_mode();
			break ;
        case 1:
            HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin|LED_YELLOW1_Pin|LED_GREEN_Pin|LED_GREEN1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_RED1_Pin , GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_RED1_Pin|LED_YELLOW_Pin|LED_YELLOW1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_GREEN1_Pin , GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_GREEN1_Pin|LED_RED_Pin|LED_RED1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin|LED_YELLOW1_Pin , GPIO_PIN_RESET);
            break;
        default:
            break;
	}
}



