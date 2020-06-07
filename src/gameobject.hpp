#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    double x, y, altitude;

    public:
        GameObject();

        // Movement
        double heading;
        double vertical_speed, vertical_accel;
        double horizontal_speed, horizontal_accel;

        ~GameObject() {}

    private:
};

#endif /* GAMEOBJECT_H */
