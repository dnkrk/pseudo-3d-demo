#ifndef WORLD_H
#define WORLD_H

#include "sdl.hpp"
#include "truck.hpp"
#include "player.hpp"
#include <iostream>
#include <vector>

class World {
    public:
        World(Player* player, Media* media);
        ~World();

        void render();

        //TODO debug method plz remove
        void rotate_truck(double degrees);

    private:
        Player* player;
        std::vector<GameObject*> objects;
        Media* media;
};

#endif /* WORLD_H */
