#include "vehicle.hpp"
#include <cmath>

void Vehicle::accelerate()
{
    if (this->horizontal_speed < this->max_speed)
    {
        this->horizontal_accel = this->acceleration_force;
    }
    if (this->horizontal_speed < 0)
    {
        this->braking = true;
    }
}


void Vehicle::yaw(const int direction)
{
    if (this->turn_angle < this->turn_limit)
    {
        this->turn_angle += this->turn_rate*direction;
    }
}


void Vehicle::brake()
{
    if (this->horizontal_speed > 0.01)
    {
        this->braking = true;
        this->horizontal_speed -= this->braking_force;
        if (this->horizontal_speed < 0) { this->horizontal_speed = 0; }
    }
    else if (this->horizontal_speed > -0.2*this->max_speed)
    {
        this->horizontal_accel = -0.5*this->acceleration_force;
    }
}


void Vehicle::update()
{
    // Update horizontal speed
    if (this->horizontal_accel != 0)
    {
        if (this->horizontal_speed < this->max_speed)
        {
            this->horizontal_speed += this->horizontal_accel;
        }
        else
        {
            this->horizontal_speed = this-> max_speed;
        }
        this->horizontal_accel = 0;
    }
    else
    {
        // Decay speed
        if (this->horizontal_speed > 0)
        {
            this->horizontal_speed -= this->coast_decay_rate;
        }
        else if (this->horizontal_speed < 0)
        {
            this->horizontal_speed += this->coast_decay_rate*2;
        }
        // Reduce speed jitter
        if (std::abs(this->horizontal_speed) < 0.005)
        {
            this->horizontal_speed = 0;
            this->braking = true;
        }
    }


    // Update heading
    double turn_factor = std::abs(this->turn_angle*(this->horizontal_speed/this->max_speed*6));
    if (turn_factor > 1) { turn_factor = 1; }
    if (this->horizontal_speed >= 0)
    {
        this->heading += this->turn_angle*turn_factor;
    }
    else
    {
        this->heading -= this->turn_angle*turn_factor;
    }

    // Roll over heading
    if (this->heading >= 360)
    {
        this->heading -= 360;
    }
    else if (this->heading < 0)
    {
        this->heading += 360;
    } 

    // Decay steering
    if (this->turn_angle > 0)
    {
        this->turn_angle -= this->turn_rate;
    }
    else if (this->turn_angle < 0)
    {
        this->turn_angle += this->turn_rate;
    }

    // Reduce steering jitter
    if (std::abs(this->turn_angle) < 0.001)
    {
        this->turn_angle = 0;
    }


    // Use speed to update position
    double r = (this->heading*3.14)/180;
    this->x += cos(r)*this->horizontal_speed;
    this->y += sin(r)*this->horizontal_speed;

    
    // Update appearance
    this->current_model = (this->braking << 1) + (this->horizontal_speed < 0);
    this->braking = false;

    /* Keep truck on screen for the purposes of the demo */
    bool is_offscreen = false;
    if (this->x <= -100)
    {
        this->x = -100;
        is_offscreen = true;
    }
    else if (this->x >= 1160)
    {
        this->x = 1160;
        is_offscreen = true;
    }
    if (this->y <= -50)
    {
        this->y = -50;
        is_offscreen = true;
    }
    else if (this->y >= 960)
    {
        this->y = 960;
        is_offscreen = true;
    }
    if (is_offscreen)
    {
        this->horizontal_accel = 0;
        this->horizontal_speed = 0;
    }
    /* end keep truck on screen */
}
