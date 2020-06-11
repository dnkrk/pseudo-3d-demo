#ifndef TERRAIN_H
#define TERRAIN_H

#include "stationaryobject.hpp"
#include "log.hpp"

class Terrain:public StationaryObject
{
    public:
        Terrain(int sprite);
        ~Terrain() {}

    private:
        int width;
        int height;
};

#endif /* TERRAIN_H */
