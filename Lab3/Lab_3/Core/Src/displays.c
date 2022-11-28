#include <displays.h>
const int MAX_LED = 4;
int buffer[4] = { 0, 0, 0, 0 };
void display7SEG(int num){
	  switch(num){
	  case 0:
		  HAL_GPIO_WritePin(GPIOB, G_7SEG_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | F_7SEG_Pin | A_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | C_7SEG_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | F_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | C_7SEG_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | G_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | A_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 3:
		  HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | E_7SEG_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | G_7SEG_Pin | D_7SEG_Pin | C_7SEG_Pin | A_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 4:
		  HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | E_7SEG_Pin | D_7SEG_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | G_7SEG_Pin | F_7SEG_Pin | C_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 5:
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | E_7SEG_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | G_7SEG_Pin | D_7SEG_Pin | C_7SEG_Pin | A_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 6:
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | G_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | C_7SEG_Pin | A_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 7:
		  HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | E_7SEG_Pin | D_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | C_7SEG_Pin | A_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 8:
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | F_7SEG_Pin | A_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  case 9:
		  HAL_GPIO_WritePin(GPIOB, E_7SEG_Pin , GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | G_7SEG_Pin | F_7SEG_Pin | A_7SEG_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
}

void update_7SEG(int index){
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

void updateClockBuffer(int horizontal, int vertical){
	buffer[0] = horizontal/10;
	buffer[1] = horizontal%10;
	buffer[2] = vertical/10;
	buffer[3] = vertical%10;
}
