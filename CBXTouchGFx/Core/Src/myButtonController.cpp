/*
 * ButtonController.cpp
 *
 *  Created on: Feb 20, 2025
 *      Author: waseem.wecuw
 */
#include "myButtonController.hpp"
#include "main.h"
#include "touchgfx/hal/HAL.hpp"

extern "C" {
extern uint8_t sel_key_state;
extern uint8_t set_key_state;
extern uint8_t inc_key_state;
extern uint8_t dec_key_state;
}

void myButtonController::init()
{
	//previousState = 0xFF;
}

bool myButtonController::sample(uint8_t &key)
{
	if(sel_key_state)
	{
		sel_key_state = 0;
		key = 0;
		return true;
	}
	else if(set_key_state)
	{
		set_key_state = 0;
		key = 1;
		return true;
	}
	else if(inc_key_state)
	{
		inc_key_state = 0;
		key = 2;
		return true;
	}
	else if(dec_key_state)
	{
		dec_key_state = 0;
		key = 3;
		return true;
	}
	return false;
}

