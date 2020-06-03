#ifndef GAME_H_DEFINED
#define GAME_H_DEFINED
#include "window.hpp"
#include "media.hpp"

class Game {
    public:
        Game(Window* window);
        ~Game();
        bool start();
    private:
        Media* media;
        Window* window;
};

#endif /* GAME_H_DEFINED */
