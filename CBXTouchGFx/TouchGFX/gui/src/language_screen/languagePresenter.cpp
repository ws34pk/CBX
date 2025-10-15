#include <gui/language_screen/languageView.hpp>
#include <gui/language_screen/languagePresenter.hpp>

languagePresenter::languagePresenter(languageView& v)
    : view(v)
{

}

void languagePresenter::activate()
{

}

void languagePresenter::deactivate()
{

}

void languagePresenter::check_buttons (uint8_t buttons_state)
{
	view.check_buttons(buttons_state);
}
