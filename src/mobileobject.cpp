#include "mobileobject.hpp"


bool MobileObject::move_to(double x, double y, double alt, double heading, bool preserve_momentum)
{
    this->x = x;
    this->y = y;
    this->altitude = alt;
    this->heading = heading;

    if (!preserve_momentum)
    {
        this->vertical_speed = 0.0;
        this->vertical_accel = 0.0;
        this->horizontal_speed = 0.0;
        this->horizontal_accel = 0.0;
    }
    return true;
}
