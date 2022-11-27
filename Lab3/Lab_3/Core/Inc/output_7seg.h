/*
 * output_7seg.h
 *
 *  Created on: Nov 20, 2022
 *      Author: DucNguyen
 */

#ifndef INC_OUTPUT_7SEG_H_
#define INC_OUTPUT_7SEG_H_
#include "main.h"
extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];
void display7SEG(int num);
void upd7Seg(int index);
void updateClockBuffer(int hori, int verti);


#endif /* INC_OUTPUT_7SEG_H_ */
