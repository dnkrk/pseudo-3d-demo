#ifndef GAME_H
#define GAME_H
#include "window.hpp"
#include "media.hpp"
#include "world.hpp"
#include "player.hpp"
#include "log.hpp"
#include "media.hpp"
#include "timer.hpp"
#include "sdl.hpp"
#include <sstream>

class Game
{
    public:
        Game(Window* window, int ticks_per_frame, bool debug_mode=false);
        ~Game();

        void start();                       // Runs the game
        void destroy();                     // Ends the game

    private:
        bool debug_mode;
        int ticks_per_frame;

        Game(const Game& a);                // copy constructor, non-copyable
        Game& operator=(const Game& a);     // copy assignment, non-copyable

        Game(Game&& a);                     // move constructor, non-movable
        Game& operator=(Game&& a);          // move assignment, non-movable

        Media* media;
        Window* window;
        World* world;
        Player* player;
};

#endif /* GAME_H */
