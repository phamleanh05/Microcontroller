#include "output_7seg.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = { 0, 0, 0, 0 };
void display7SEG(int num){
	switch (num){
	  case 0:
		  HAL_GPIO_WritePin(GPIOB,G_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,B_Pin|C_Pin|D_Pin
		                           |E_Pin|F_Pin|A_Pin, GPIO_PIN_RESET);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(GPIOB,B_Pin|C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB,A_Pin|D_Pin
		  		                           |E_Pin|F_Pin|G_Pin, GPIO_PIN_SET);
	  		  break;
	  case 2:
		  HAL_GPIO_WritePin(GPIOB,F_Pin|C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,B_Pin|G_Pin|D_Pin
		  		                           |E_Pin|A_Pin, GPIO_PIN_RESET);
	  		  break;
	  case 3:
		  HAL_GPIO_WritePin(GPIOB,F_Pin|E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,B_Pin|G_Pin|D_Pin
		  		  		                   |C_Pin|A_Pin, GPIO_PIN_RESET);
	  		  break;
	  case 4:
		  HAL_GPIO_WritePin(GPIOB,A_Pin|E_Pin|D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,B_Pin|G_Pin|F_Pin
		  		  		  		           |C_Pin, GPIO_PIN_RESET);
	  		  break;
	  case 5:
		  HAL_GPIO_WritePin(GPIOB,B_Pin|E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,F_Pin|G_Pin|D_Pin
		  		  		  		           |C_Pin|A_Pin, GPIO_PIN_RESET);
	  		  break;
	  case 6:
		  HAL_GPIO_WritePin(GPIOB,B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,F_Pin|G_Pin|D_Pin|E_Pin
		  		  		  		  		   |C_Pin|A_Pin, GPIO_PIN_RESET);
	  		  break;
	  case 7:
		  HAL_GPIO_WritePin(GPIOB,F_Pin|E_Pin|D_Pin|G_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,B_Pin|C_Pin|A_Pin, GPIO_PIN_RESET);
	  		  break;
	  case 8:
		  HAL_GPIO_WritePin(GPIOB,B_Pin|C_Pin|D_Pin
		 		                           |E_Pin|F_Pin|A_Pin|G_Pin, GPIO_PIN_RESET);
	  		  break;
	  case 9:
		  HAL_GPIO_WritePin(GPIOB,E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB,B_Pin|C_Pin|D_Pin
		  		                           |G_Pin|F_Pin|A_Pin, GPIO_PIN_RESET);
	  		  break;
	  default:
	  		  break;
	  }

}
void upd7Seg(int index){
	HAL_GPIO_WritePin(GPIOA,EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);
	switch(index){
		case 0:
			HAL_GPIO_WritePin(GPIOA,EN0_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA,EN1_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA,EN2_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA,EN3_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
	display7SEG(led_buffer[index]);
}

void updateClockBuffer(int hori, int verti){
	led_buffer[0] = hori/10;
	led_buffer[1] = hori%10;
	led_buffer[2] = verti/10;
	led_buffer[3] = verti%10;
}
