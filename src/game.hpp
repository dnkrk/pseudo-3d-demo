#ifndef GAME_H
#define GAME_H
#include "window.hpp"
#include "media.hpp"
#include "world.hpp"
#include "player.hpp"
#include "log.hpp"
#include "media.hpp"
#include "sdl.hpp"

class Game
{
    public:
        Game(Window* window, bool debug_mode=false);
        ~Game();

        void start();                       // Runs the game
        void destroy();                     // Ends the game

    private:
        bool debug_mode;

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
