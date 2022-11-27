
#include "input_processing.h"


enum ButtonState { BUTTON_RELEASED , PRESSED_BUTTON_0 , PRESSED_BUTTON_1 , PRESSED_BUTTON_2 } ;
enum ButtonState button = BUTTON_RELEASED ;

void fsm_for_input_processing ( void ){
	switch ( button ){
		case BUTTON_RELEASED :
			if( is_button_pressed (0) ){
				button = PRESSED_BUTTON_0 ;
				mode++;
				if(mode >= NO_OF_MODES){
					mode = 0;
					if (led_time[Red] == 0 || led_time[Green] == 0 || led_time[Yellow] == 0){
						light_state = Idle;
						led_time_buffer[Red] = led_time_buffer[Green] = led_time_buffer[Yellow] = 0;
						updateClockBuffer(0,mode);
					}
					else{
						light_state = Red;
						horizontal_countdown = led_time[Red];
						vertical_countdown = led_time[Green];
					}
				}
				else {
					light_state = Idle;
					updateClockBuffer(led_time_buffer[mode-1],mode);
				}
			}
			else if ( is_button_pressed (1) ){
				button = PRESSED_BUTTON_1;
				if (mode > 0 && mode < NO_OF_MODES){
					led_time_buffer[mode-1]++;
					updateClockBuffer(led_time_buffer[mode-1], mode);
				}
			}
			else if ( is_button_pressed (2) ){
				button = PRESSED_BUTTON_2;
				if (mode > 0 && mode < NO_OF_MODES){
					led_time[mode-1] = led_time_buffer[mode-1];
				}
			}
			break ;
		case PRESSED_BUTTON_0 :
			if (! is_button_pressed (0) ){
				button = BUTTON_RELEASED ;
			}
			break ;
		case PRESSED_BUTTON_1 :
			if (! is_button_pressed (1) ){
				button = BUTTON_RELEASED ;
			}

			break ;
		case PRESSED_BUTTON_2 :
			if (! is_button_pressed (2) ){
				button = BUTTON_RELEASED ;
				}

			break ;
		default:
			break;
	}
}
