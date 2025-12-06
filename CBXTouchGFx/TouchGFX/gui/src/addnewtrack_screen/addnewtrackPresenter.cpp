#include <gui/addnewtrack_screen/addnewtrackView.hpp>
#include <gui/addnewtrack_screen/addnewtrackPresenter.hpp>

addnewtrackPresenter::addnewtrackPresenter(addnewtrackView& v)
    : view(v)
{

}

void addnewtrackPresenter::activate()
{

}

void addnewtrackPresenter::deactivate()
{

}

void addnewtrackPresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
