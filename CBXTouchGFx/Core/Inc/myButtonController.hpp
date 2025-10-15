#ifndef myBUTTONCONTROLLER_HPP_
#define myBUTTONCONTROLLER_HPP_

#include <platform/driver/button/ButtonController.hpp>

class myButtonController : public touchgfx::ButtonController
{
	virtual void init();
	virtual bool sample(uint8_t& key);

private:
	uint8_t previousState;
};

#endif /* myBUTTONCONTROLLER_HPP_ */

