

#ifndef INC_NORMAL_MODE_H_
#define INC_NORMAL_MODE_H_
#include "main.h"
#include "output_7seg.h"
#include "input_processing.h"

void traffic_light(void);
extern int led_time[3];
extern int led_time_buffer[3];
extern int horizontal_countdown;
extern int vertical_countdown;

enum LightState {Red, Green , Yellow, Idle};
extern enum LightState light_state;
#endif /* INC_NORMAL_MODE_H_ */
