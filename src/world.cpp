#include "world.hpp"

World::World(Player* player, Media* media)
{
    this->player = player;
    this->media = media;

    Truck* truck = new Truck();
    truck->move_to(100, 100, 0, 45);
    player->set_vehicle(truck);
    this->objects.push_back(truck);
};


World::~World()
{
    for (auto obj : this->objects)
    {
        delete obj;
    }
};


void World::render()
{
    for (auto obj : this->objects)
    {
        obj->render(this->media);
    }
}

void World::update()
{
    for (auto obj : this->objects)
    {
        obj->update();
    }
}
