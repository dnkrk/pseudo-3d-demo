#ifndef GAME_H
#define GAME_H
#include "window.hpp"
#include "media.hpp"
#include "world.hpp"
#include "log.hpp"
#include "media.hpp"
#include "sdl.hpp"

class Game
{
    public:
        Game(Window* window);
        ~Game();

        void start();                       // Runs the game
        void destroy();                     // Ends the game

    private:
        Game(const Game& a);                // copy constructor, non-copyable
        Game& operator=(const Game& a);     // copy assignment, non-copyable

        Game(Game&& a);                     // move constructor, non-movable
        Game& operator=(Game&& a);          // move assignment, non-movable

        Media* g_media;
        Window* g_window;
        World* g_world;
};

#endif /* GAME_H */
