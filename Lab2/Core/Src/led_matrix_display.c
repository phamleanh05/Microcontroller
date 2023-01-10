#include "main.h"

#define LED_MATRIX_1_A			GPIO_PIN_2
#define LED_MATRIX_1_A_PORT		GPIOA
#define LED_MATRIX_1_B			GPIO_PIN_3
#define LED_MATRIX_1_B_PORT		GPIOA
#define LED_MATRIX_1_C			GPIO_PIN_10
#define LED_MATRIX_1_C_PORT		GPIOA
#define LED_MATRIX_1_D			GPIO_PIN_11
#define LED_MATRIX_1_D_PORT		GPIOA
#define LED_MATRIX_1_E			GPIO_PIN_12
#define LED_MATRIX_1_E_PORT		GPIOA
#define LED_MATRIX_1_F			GPIO_PIN_13
#define LED_MATRIX_1_F_PORT		GPIOA
#define LED_MATRIX_1_G			GPIO_PIN_14
#define LED_MATRIX_1_G_PORT		GPIOA
#define LED_MATRIX_1_H			GPIO_PIN_15
#define LED_MATRIX_1_H_PORT		GPIOA

void displayMatrix (uint8_t num){
	  uint8_t temp = num;
		if(temp & 0x01){ //what is the value of temp & 0x01 = 0x01 --> TRUE
			HAL_GPIO_WritePin(LED_MATRIX_1_A_PORT, LED_MATRIX_1_A, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_A_PORT, LED_MATRIX_1_A, RESET);
		}

		if(temp & 0x02){
			HAL_GPIO_WritePin(LED_MATRIX_1_B_PORT, LED_MATRIX_1_B, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_B_PORT, LED_MATRIX_1_B, RESET);
		}

		if(temp & 0x04){
			HAL_GPIO_WritePin(LED_MATRIX_1_C_PORT, LED_MATRIX_1_C, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_C_PORT, LED_MATRIX_1_C, RESET);
		}

		if(temp & 0x08){
			HAL_GPIO_WritePin(LED_MATRIX_1_D_PORT, LED_MATRIX_1_D, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_D_PORT, LED_MATRIX_1_D, RESET);
		}

		if(temp & 0x10){
			HAL_GPIO_WritePin(LED_MATRIX_1_E_PORT, LED_MATRIX_1_E, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_E_PORT, LED_MATRIX_1_E, RESET);
		}
	//
		if(temp & 0x20){
			HAL_GPIO_WritePin(LED_MATRIX_1_F_PORT, LED_MATRIX_1_F, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_F_PORT, LED_MATRIX_1_F, RESET);
		}
	//	//temp = 0x3f
		if(temp & 0x40){ //true or false?
	 		HAL_GPIO_WritePin(LED_MATRIX_1_G_PORT, LED_MATRIX_1_G, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_G_PORT, LED_MATRIX_1_G, RESET);
		}
		if(temp & 0x80){ //what is the value of temp & 0x01 = 0x01 --> TRUE
			HAL_GPIO_WritePin(LED_MATRIX_1_H_PORT, LED_MATRIX_1_H, SET);
		} else{
			HAL_GPIO_WritePin(LED_MATRIX_1_H_PORT, LED_MATRIX_1_H, RESET);
		}
  }

uint8_t displayChange(uint8_t data){
//	return ~data;
	return ~(((~data)<<1) | (((~data)>>7)&1));
}
