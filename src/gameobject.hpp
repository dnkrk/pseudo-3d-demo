#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "media.hpp"
#include "log.hpp"

class GameObject
{
    public:
        virtual ~GameObject();

        virtual void render(Media* media);
        virtual bool move_to(double x, double y, double alt, double heading, bool preserve_momentum=false);
        virtual void update() = 0;

        virtual int get_y() { return y; };

    protected:
        int current_model;
        int shadow_sprite;
        std::vector<std::vector<int>> layers;
        double x, y, altitude, scale, heading;
};

#endif /* GAMEOBJECT_H */
