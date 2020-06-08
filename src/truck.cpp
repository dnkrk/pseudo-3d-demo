#include "truck.hpp"

Truck::Truck()
{
    this->x = 10;
    this->y = 10;
    this->altitude = 0;
    this->scale = 5;

    // Handling characteristics
    this->acceleration_force = 0.6;
    this->braking_force = 0.8;
    this->turn_radius = 1.3;
    this->turn_rate = 0.8;
    this->coast_decay_rate = 1.1;

    // Current state
    this->heading = 0.0;
    this->vertical_speed = 0.0;
    this->vertical_accel = 0.0;
    this->horizontal_speed = 0.0;
    this->horizontal_accel = 0.0;

    // Visual model
    this->layers = {0, 1, 2, 11, 3, 15, 4, 4, 5, 5, 4, 6, 6, 6, 6, 7, 8, 8, 9};
}
