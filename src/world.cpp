#include "world.hpp"

World::World(Player* player, Media* media)
{
    this->player = player;
    this->media = media;

    Truck* truck = new Truck();
    truck->move_to(100, 100, 0, 45);
    //w_player->set_vehicle(truck);

    this->objects.push_back(truck);
};


World::~World()
{
    // TODO is this right?
    delete[] &this->objects;
};


void World::render()
{
    for (auto obj : this->objects)
    {
        obj->render(this->media);
    }
}


void World::rotate_truck(double degrees)
{
    this->objects[0]->yaw(1);
}
