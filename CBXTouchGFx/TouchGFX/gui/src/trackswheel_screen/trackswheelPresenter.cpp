#include <gui/trackswheel_screen/trackswheelView.hpp>
#include <gui/trackswheel_screen/trackswheelPresenter.hpp>

trackswheelPresenter::trackswheelPresenter(trackswheelView& v)
    : view(v)
{

}

void trackswheelPresenter::activate()
{

}

void trackswheelPresenter::deactivate()
{

}

void trackswheelPresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
