#ifndef TRACKSWHEELPRESENTER_HPP
#define TRACKSWHEELPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class trackswheelView;

class trackswheelPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    trackswheelPresenter(trackswheelView& v);

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

    virtual ~trackswheelPresenter() {}

    virtual void check_buttons (uint8_t buttons_state);

private:
    trackswheelPresenter();

    trackswheelView& view;
};

#endif // TRACKSWHEELPRESENTER_HPP
