#include <gui/recordtrack_screen/recordtrackView.hpp>
#include <gui/recordtrack_screen/recordtrackPresenter.hpp>

recordtrackPresenter::recordtrackPresenter(recordtrackView& v)
    : view(v)
{

}

void recordtrackPresenter::activate()
{

}

void recordtrackPresenter::deactivate()
{

}

void recordtrackPresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
