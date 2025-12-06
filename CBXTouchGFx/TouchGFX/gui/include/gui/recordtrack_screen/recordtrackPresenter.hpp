#ifndef RECORDTRACKPRESENTER_HPP
#define RECORDTRACKPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class recordtrackView;

class recordtrackPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    recordtrackPresenter(recordtrackView& v);

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

    virtual ~recordtrackPresenter() {}

    virtual void check_buttons (uint8_t buttons_state);

private:
    recordtrackPresenter();

    recordtrackView& view;
};

#endif // RECORDTRACKPRESENTER_HPP
