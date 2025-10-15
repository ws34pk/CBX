#include <gui/settings_screen/settingsView.hpp>
#include <gui/settings_screen/settingsPresenter.hpp>

settingsPresenter::settingsPresenter(settingsView& v)
    : view(v)
{

}

void settingsPresenter::activate()
{

}

void settingsPresenter::deactivate()
{

}

void settingsPresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
