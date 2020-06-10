#include "truck.hpp"

Truck::Truck()
{
    this->x = 10;
    this->y = 10;
    this->altitude = 0;
    this->scale = 5;

    // Handling characteristics
    this->acceleration_force = 0.2;
    this->braking_force = 0.2;
    this->turn_limit = 4.3;
    this->turn_rate = 1.2;
    this->coast_decay_rate = 0.1;
    this->max_speed = 40;

    // Current state
    this->heading = 0.0;
    this->turn_angle = 0.0;
    this->vertical_speed = 0.0;
    this->vertical_accel = 0.0;
    this->horizontal_speed = 0.0;
    this->horizontal_accel = 0.0;
    this->braking = false;

    // Visual model
    this->current_model = 0;
    this->layers = {
        {1, 2, 11, 3, 15, 4, 4, 5, 5, 4, 6, 6, 6, 6, 7, 8, 8, 9},
        {1, 2, 10, 3, 15, 4, 4, 5, 5, 4, 6, 6, 6, 6, 7, 8, 8, 9},
        {1, 2, 12, 3, 15, 4, 4, 5, 5, 4, 6, 6, 6, 6, 7, 8, 8, 14},
        {1, 2, 13, 3, 15, 4, 4, 5, 5, 4, 6, 6, 6, 6, 7, 8, 8, 14}
    };
}
