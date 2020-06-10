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
        virtual bool operator()(const GameObject& a, const GameObject& b);

        virtual void yaw(int direction) {}
        virtual int get_y() { return y; };
        //virtual void accelerate(int direction) = 0;
        //virtual void brake(int direction) = 0;

    protected:
        int current_model;
        int shadow_sprite;
        std::vector<std::vector<int>> layers;
        double x, y, altitude, scale;

        // Movement state
        double heading;
        double vertical_speed, vertical_accel;
        double horizontal_speed, horizontal_accel;
};

#endif /* GAMEOBJECT_H */
