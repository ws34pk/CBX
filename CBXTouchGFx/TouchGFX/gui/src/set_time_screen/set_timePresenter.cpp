#include <gui/set_time_screen/set_timeView.hpp>
#include <gui/set_time_screen/set_timePresenter.hpp>

set_timePresenter::set_timePresenter(set_timeView& v)
    : view(v)
{

}

void set_timePresenter::activate()
{

}

void set_timePresenter::deactivate()
{

}

void set_timePresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
