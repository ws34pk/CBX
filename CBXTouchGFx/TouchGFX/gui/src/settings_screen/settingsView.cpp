#include <gui/settings_screen/settingsView.hpp>
#include <touchgfx/Color.hpp>
settingsView::settingsView()
{

}

void settingsView::setupScreen()
{
    settingsViewBase::setupScreen();
}

void settingsView::tearDownScreen()
{
    settingsViewBase::tearDownScreen();
}

void settingsView::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x01)
		static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen1ScreenNoTransition();
	if(buttons_state == 0x02) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gotolanguageScreenNoTransition();
		if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			static_cast<FrontendApplication*>(Application::getInstance())->gototime_dateScreenNoTransition();
		box1.invalidate();
		//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
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
			box5.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box5.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
		//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	}
	if(buttons_state == 0x08) {
		if(box2.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box5.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box3.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box2.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box4.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box3.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(box5.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			box5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			box4.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
		//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	}
}
