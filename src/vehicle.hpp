#ifndef VEHICLE_H
#define VEHICLE_H

#include <math.h>
#include "gameobject.hpp"
#include "log.hpp"

class Vehicle:public GameObject
{
    public:
        virtual ~Vehicle() {}

        virtual void update();
        virtual void accelerate();
        virtual void yaw(const int direction);
        virtual void brake();

    protected:
        // Handling statistics
        double acceleration_force;
        double braking_force;
        double turn_limit;
        double turn_rate;
        double turn_angle;
        double coast_decay_rate;
        double max_speed;
        bool braking;
};

#endif /* VEHICLE_H */
