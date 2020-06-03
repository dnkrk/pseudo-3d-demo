#ifndef GAMEOBJECT_H_DEFINED
#define GAMEOBJECT_H_DEFINED

class GameObject {
    public:
        GameObject();
    private:
        // Location
        double x;
        double y;
        double altitude;

        // Movement
        double heading;
        double vertical_speed;
        double vertical_accel;
        double horizontal_speed;
        double horizontal_accel;

        // State
        int max_health;  // -1 for indestructible objects
        int current_health;
};

#endif /* GAMEOBJECT_H_DEFINED */
