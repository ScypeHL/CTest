#ifndef UTILS_H
#define UTILS_H

#include "game.h"

typedef enum
{
    BUTTON_0 = 0,
	BUTTON_1,
    BUTTON_2,
    BUTTON_3,
	BUTTON_4,
	BUTTON_5,
	BUTTON_6,
	BUTTON_7,
	BUTTON_8,
	BUTTON_9,
	BUTTON_EQUAL,
	BUTTON_PLUS,
	BUTTON_MINUS,
	BUTTON_DIVIDE,
    BUTTON_TIMES
}ButtonType; 

bool IsColliding(Mouse mouse, Entity button);

#endif
