#include "world.hpp"

World::World(Player* player, Media* media)
{
    this->player = player;
    this->media = media;

    Truck* truck = new Truck();
    truck->move_to(100, 100, 0, 45);
    player->set_vehicle(truck);

    Truck* truck2 = new Truck();
    truck2->move_to(100, 130, 0, 45);

    this->objects.push_back(truck);
    this->objects.push_back(truck2);

};


World::~World()
{
    delete[] &this->objects;
};


void World::render()
{
    // For low number of objects, this works well enough, but scales poorly.
    std::sort(this->objects.begin(), this->objects.end(), GameObjectComparisonKey());

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
