#ifndef SET_TIMEPRESENTER_HPP
#define SET_TIMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class set_timeView;

class set_timePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    set_timePresenter(set_timeView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~set_timePresenter() {}

    virtual void check_buttons (uint8_t buttons_state);

private:
    set_timePresenter();

    set_timeView& view;
};

#endif // SET_TIMEPRESENTER_HPP
