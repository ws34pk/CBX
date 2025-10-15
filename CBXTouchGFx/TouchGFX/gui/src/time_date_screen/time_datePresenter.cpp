#include <gui/time_date_screen/time_dateView.hpp>
#include <gui/time_date_screen/time_datePresenter.hpp>

time_datePresenter::time_datePresenter(time_dateView& v)
    : view(v)
{

}

void time_datePresenter::activate()
{

}

void time_datePresenter::deactivate()
{

}

void time_datePresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
