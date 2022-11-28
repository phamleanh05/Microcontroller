#include "main.h"
#include "input_reading.h"
#include "timer.h"

int traffic_light_counter = 101, led_7seg_counter = 25;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		button_reading();
	}
}

