#include "player.hpp"

Player::Player()
{
    piloted_vehicle = nullptr;
}


Player::~Player()
{
}


bool Player::set_vehicle(Vehicle* veh)
{
    piloted_vehicle = veh;
    return true;
}


void Player::go(const char& c)
{
    if (piloted_vehicle == nullptr)
    {
        Log::error("Player's vehicle is unset, cannot command vehicle");
        return;
    }
    switch (c) {
        case 'f':
            piloted_vehicle->accelerate();
            break;
        case 'l':
            piloted_vehicle->yaw(-1);
            break;
        case 'b':
            piloted_vehicle->brake();
            break;
        case 'r':
            piloted_vehicle->yaw(1);
            break;
    }

}
