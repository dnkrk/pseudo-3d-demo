#ifndef STATIONARYOBJECT_H
#define STATIONARYOBJECT_H

#include "gameobject.hpp"

class StationaryObject:public GameObject
{
    public:
        virtual ~StationaryObject() {}

        virtual void update();
};

#endif /* ifndef STATIONARYOBJECT_H */
