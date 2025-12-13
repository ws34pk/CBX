#include <gui/trackslist_screen/trackslistView.hpp>
#include <gui/trackslist_screen/trackslistPresenter.hpp>

trackslistPresenter::trackslistPresenter(trackslistView& v)
    : view(v)
{

}

void trackslistPresenter::activate()
{

}

void trackslistPresenter::deactivate()
{

}


void trackslistPresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
