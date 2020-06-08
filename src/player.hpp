#ifndef PLAYER_H
#define PLAYER_H

#include "vehicle.hpp"
#include "log.hpp"

class Player
{
    public:
        Player();
        ~Player();

        void go(const char& c);
        bool set_vehicle(Vehicle* veh);

    private:
        Vehicle* piloted_vehicle;
};

#endif /* PLAYER_H */
