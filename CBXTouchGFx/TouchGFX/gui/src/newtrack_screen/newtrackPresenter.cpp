#include <gui/newtrack_screen/newtrackView.hpp>
#include <gui/newtrack_screen/newtrackPresenter.hpp>

newtrackPresenter::newtrackPresenter(newtrackView& v)
    : view(v)
{

}

void newtrackPresenter::activate()
{

}

void newtrackPresenter::deactivate()
{

}

void newtrackPresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
