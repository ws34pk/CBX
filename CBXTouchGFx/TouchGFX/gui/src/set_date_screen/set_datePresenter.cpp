#include <gui/set_date_screen/set_dateView.hpp>
#include <gui/set_date_screen/set_datePresenter.hpp>

set_datePresenter::set_datePresenter(set_dateView& v)
    : view(v)
{

}

void set_datePresenter::activate()
{

}

void set_datePresenter::deactivate()
{

}

void set_datePresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
