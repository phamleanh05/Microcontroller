#include "main.h"
#include "normal_mode.h"

enum LightState light_state = Idle;
int led_time[3] = {0,0,0};
int led_time_buffer[3] = {0,0,0};
int horizontal_countdown = 0;
int vertical_countdown = 0;

void traffic_light(void){
	switch(light_state){
		case Idle:
			HAL_GPIO_WritePin(GPIOA,R1_Pin|Y1_Pin|G1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA,G0_Pin|Y0_Pin|R0_Pin, GPIO_PIN_SET);
			break;
		case Red:
			horizontal_countdown--;
			vertical_countdown--;
			updateClockBuffer(horizontal_countdown, vertical_countdown);
			HAL_GPIO_WritePin(GPIOA,R1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA,Y1_Pin|G1_Pin, GPIO_PIN_SET);
			if(horizontal_countdown - led_time[Yellow] >= 0){
				HAL_GPIO_WritePin(GPIOA,G0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,Y0_Pin|R0_Pin, GPIO_PIN_SET);
			}
			else{
				HAL_GPIO_WritePin(GPIOA,Y0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,G0_Pin|R0_Pin, GPIO_PIN_SET);
			}


			if(horizontal_countdown == 0) {
				light_state = Green;
			     horizontal_countdown = led_time[Green];
			     vertical_countdown = led_time[Red];
			     break;
			}
			if(vertical_countdown == 0) {
				vertical_countdown = led_time[Yellow];
			}

			break;
		case Green:
			horizontal_countdown--;
			vertical_countdown--;
			updateClockBuffer(horizontal_countdown, vertical_countdown);
			HAL_GPIO_WritePin(GPIOA,R0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA,Y0_Pin|G0_Pin, GPIO_PIN_SET);
			if(vertical_countdown - led_time[Yellow] >= 0){
				HAL_GPIO_WritePin(GPIOA,G1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,Y1_Pin|R1_Pin, GPIO_PIN_SET);
			}
			if (horizontal_countdown == 0){
				light_state = Yellow;
				horizontal_countdown = led_time[Yellow];
				break;
			}

			break;
		case Yellow:
			vertical_countdown--;
			horizontal_countdown--;
			updateClockBuffer(horizontal_countdown, vertical_countdown);
			HAL_GPIO_WritePin(GPIOA,R0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA,Y0_Pin|G0_Pin, GPIO_PIN_SET);
			if(horizontal_countdown >= 0){
				HAL_GPIO_WritePin(GPIOA,Y1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,G1_Pin|R1_Pin, GPIO_PIN_SET);
			}
			if (horizontal_countdown == 0){
				light_state = Red;
				horizontal_countdown = led_time[Red];
				vertical_countdown = led_time[Green];
				break;
			}

			break;
		default:
			break;
	}

}



