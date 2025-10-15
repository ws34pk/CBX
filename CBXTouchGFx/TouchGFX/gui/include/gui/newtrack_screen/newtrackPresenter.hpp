#ifndef NEWTRACKPRESENTER_HPP
#define NEWTRACKPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class newtrackView;

class newtrackPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    newtrackPresenter(newtrackView& v);

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

    virtual ~newtrackPresenter() {}

    virtual void check_buttons (uint8_t buttons_state);

private:
    newtrackPresenter();

    newtrackView& view;
};

#endif // NEWTRACKPRESENTER_HPP
