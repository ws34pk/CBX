#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>



#ifndef	SIMULATOR
#include "main.h"
#endif

extern "C" {
extern volatile uint32_t button_dly;
}

Model::Model() : modelListener(0), buttons_state(0)
{
}

void Model::tick()
{
#ifndef	SIMULATOR
	if(button_dly + 200 > HAL_GetTick())
		return;
	button_dly = HAL_GetTick();
	if (HAL_GPIO_ReadPin(SEL_KEY_GPIO_Port, SEL_KEY_Pin) == GPIO_PIN_RESET)
		buttons_state = 0x01;
	else if (HAL_GPIO_ReadPin(SET_KEY_GPIO_Port, SET_KEY_Pin) == GPIO_PIN_RESET)
		buttons_state = 0x02;
	else if (HAL_GPIO_ReadPin(INC_KEY_GPIO_Port, INC_KEY_Pin) == GPIO_PIN_RESET)
		buttons_state = 0x04;
	else if (HAL_GPIO_ReadPin(DEC_KEY_GPIO_Port, DEC_KEY_Pin) == GPIO_PIN_RESET)
		buttons_state = 0x08;
	else
		buttons_state = 0;
	//buttons_state = HAL_GPIO_ReadPin(SET_KEY_GPIO_Port, SET_KEY_Pin);
#endif

	modelListener->check_buttons(buttons_state);
}

