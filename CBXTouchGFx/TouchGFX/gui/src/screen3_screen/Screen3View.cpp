#include <texts/TextKeysAndLanguages.hpp>
#include <gui/screen3_screen/Screen3View.hpp>
#include <touchgfx/Color.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x02) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen4ScreenNoTransition();
		else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	}
	if(buttons_state == 0x04) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
	}
	if(buttons_state == 0x08) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
	}
}



