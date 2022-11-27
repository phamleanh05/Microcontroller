#include "main.h"
#include "input_reading.h"
#include "mode_processing.h"
#include "normal_mode.h"


int mode = 0;
const int NO_OF_MODES = 4;

void mode_changing(int mode){
	switch ( mode ){
		case 0 :
			traffic_light();
			break ;
        case 1:
            HAL_GPIO_WritePin(GPIOA, Y0_Pin|Y1_Pin|G0_Pin|G1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, R0_Pin|R1_Pin , GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, R0_Pin|R1_Pin|Y0_Pin|Y1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, G0_Pin|G1_Pin , GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, G0_Pin|G1_Pin|R0_Pin|R1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, Y0_Pin|Y1_Pin , GPIO_PIN_RESET);
            break;
        default:
            break;
	}
}



