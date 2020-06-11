#include "terrain.hpp"

Terrain::Terrain(int sprite)
{
    this->x = 0;
    this->y = 0;
    this->altitude = 0;
    this->scale = 5;
    this->heading = 0;

    this->width = 500;
    this->height = 500;

    this->current_model = 0;
    this->shadow_sprite = -1;
    this->layers = { {sprite} };
}
