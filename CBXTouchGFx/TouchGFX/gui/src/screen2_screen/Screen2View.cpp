#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/Color.hpp>
Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x02) {


	}
	if(buttons_state == 0x04) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box4.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
	}
		box1.invalidate();
			//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
		if(buttons_state == 0x08) {
			if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box4.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			} else if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
				box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
				box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
			}
		}
			box1.invalidate();
}
