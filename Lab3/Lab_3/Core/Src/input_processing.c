#include "main.h"
#include "input_reading.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;
void fsm_for_input_processing(void){
	switch(buttonState){
	case BUTTON_RELEASED:
		if( is_button_pressed (0) ){
						button = PRESSED_BUTTON_0 ;
						mode++;
						if(mode >= NO_OF_MODES){
							mode = 0;
							if (led[1] == 0 || led[2] == 0 || led[3] == 0){
								state = 0;
								led_buffer[1] = led_buffer[2] = led_buffer[3] = 0;
								updateClockBuffer(0,mode);
							}
							else{
								state = 1;
								horizontal = led[1];
								vertical = led[2];
							}
						}
						else {
							state = 0;
							updateClockBuffer(led_buffer[mode-1],mode);
						}
					}
					else if ( is_button_pressed (1) ){
						button = PRESSED_BUTTON_1;
						if (mode > 0 && mode < NO_OF_MODES){
							led_buffer[mode-1]++;
							updateClockBuffer(led_buffer[mode-1], mode);
						}
					}
					else if ( is_button_pressed (2) ){
						button = PRESSED_BUTTON_2;
						if (mode > 0 && mode < NO_OF_MODES){
							led[mode-1] = led_buffer[mode-1];
						}
					}
					break ;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(0)){
				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		}
		//todo
		break;
	}
}
