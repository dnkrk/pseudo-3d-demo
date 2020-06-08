#include "vehicle.hpp"

        //virtual void accelerate();
        //virtual void yaw(const int direction);
        //virtual void brake();
void Vehicle::accelerate()
{
    this->horizontal_speed += this->acceleration_force;
}


void Vehicle::yaw(const int direction)
{
    Log::debug("turning is not implemented");
    this->heading += 0.01;
}


void Vehicle::brake()
{
    this->horizontal_speed += this->acceleration_force;
    Log::debug("turning is not implemented");
}
