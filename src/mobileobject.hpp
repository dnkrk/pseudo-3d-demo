#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include "gameobject.hpp"

class MobileObject:public GameObject
{
    public:
        virtual ~MobileObject() {}

        virtual bool move_to(double x, double y, double alt, double heading, bool preserve_momentum=false) override;
        virtual void yaw(int direction) {}

    protected:
        double vertical_speed, vertical_accel;
        double horizontal_speed, horizontal_accel;

};

#endif /* ifndef MOBILEOBJECT_H */
