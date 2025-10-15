#ifndef TIME_DATEPRESENTER_HPP
#define TIME_DATEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class time_dateView;

class time_datePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    time_datePresenter(time_dateView& v);

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

    virtual ~time_datePresenter() {}

    virtual void check_buttons (uint8_t buttons_state);

private:
    time_datePresenter();

    time_dateView& view;
};

#endif // TIME_DATEPRESENTER_HPP
