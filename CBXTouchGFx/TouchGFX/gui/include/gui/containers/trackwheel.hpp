#ifndef TRACKWHEEL_HPP
#define TRACKWHEEL_HPP

#include <gui_generated/containers/trackwheelBase.hpp>

class trackwheel : public trackwheelBase
{
public:
    trackwheel();
    virtual ~trackwheel() {}

    virtual void initialize();

    void setListElements(int item);
protected:
};

#endif // TRACKWHEEL_HPP
