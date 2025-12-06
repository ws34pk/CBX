#include <gui/addnewtrack_screen/addnewtrackView.hpp>
#include <touchgfx/Color.hpp>
addnewtrackView::addnewtrackView()
{

}

void addnewtrackView::setupScreen()
{
    addnewtrackViewBase::setupScreen();
}

void addnewtrackView::tearDownScreen()
{
    addnewtrackViewBase::tearDownScreen();
}

void addnewtrackView::check_buttons(uint8_t buttons_state)
{
	if(buttons_state == 0x02) {
		if(recordbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			//add new track screen
			static_cast<FrontendApplication*>(Application::getInstance())->gotorecordtrackScreenNoTransition();
			//else
				//otherwise add a new track
				//static_cast<FrontendApplication*>(Application::getInstance())->gotonewtrackScreenNoTransition();
			//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
		}
		if(backbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0))
			//return to the main menu
			static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen1ScreenNoTransition();

	}
	if(buttons_state == 0x04) {
		if(recordbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			recordbox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			backbox.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		} else if(backbox.getColor() == touchgfx::Color::getColorFromRGB(0xff, 0x49, 0)) {
			backbox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
			recordbox.setColor(touchgfx::Color::getColorFromRGB(0xff, 0x49, 0));
		}
		box1.invalidate();
			//static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen2ScreenNoTransition();
	}
}
