#ifndef INC_DISPLAYS_H_
#define INC_DISPLAYS_H_
#include "main.h"
extern const int MAX_LED;
extern int buffer[4];
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int horizontal, int vertical);


#endif /* INC_DISPLAYS_H_ */
