#include "gameobject.hpp"

GameObject::~GameObject()
{
}


void GameObject::render(Media* media)
{
    int screen_x = this->x;
    int screen_y = this->y;
    int screen_rotation = this->heading;
    if (this->shadow_sprite >= 0)
    {
        media->render_at(screen_x, screen_y, this->shadow_sprite,
                this->scale, screen_rotation);
    }
    for (int i=0; i <= this->layers[this->current_model].size(); ++i)
    {
        media->render_at(screen_x, screen_y - i*this->scale,
                this->layers[this->current_model][i],
                this->scale, screen_rotation);
    }
}


bool GameObject::move_to(double x, double y, double alt,
        double heading, bool preserve_momentum)
{
    this->x = x;
    this->y = y;
    this->altitude = alt;
    this->heading = heading;
    return true;
}
