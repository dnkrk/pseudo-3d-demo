#ifndef VEHICLE_H
#define VEHICLE_H

#include "gameobject.hpp"
#include "log.hpp"

class Vehicle:public GameObject
{
    public:
        virtual ~Vehicle() {}

        virtual void accelerate();
        virtual void yaw(const int direction);
        virtual void brake();

    protected:
        // Handling statistics
        double acceleration_force;
        double braking_force;
        double turn_radius;
        double turn_rate;
        double coast_decay_rate;
};

#endif /* VEHICLE_H */
