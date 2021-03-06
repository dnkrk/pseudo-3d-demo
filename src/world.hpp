#ifndef WORLD_H
#define WORLD_H

#include "sdl.hpp"
#include "truck.hpp"
#include "terrain.hpp"
#include "player.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

class World {
    public:
        World(Player* player, Media* media);
        ~World();

        void render();
        void update();

    private:
        Player* player;
        std::vector<GameObject*> objects;
        Media* media;
};

#endif /* WORLD_H */
