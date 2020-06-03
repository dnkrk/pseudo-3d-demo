#include "gameobject.hpp"

GameObject::GameObject() {
        x = 0.0;
        y = 0.0;
        altitude = 0.0;

        heading = 0.0;
        vertical_speed = 0.0;
        vertical_accel = 0.0;
        horizontal_speed = 0.0;
        horizontal_accel = 0.0;

        max_health = 0;  // -1 for indestructible objects
        current_health = 0;
}
