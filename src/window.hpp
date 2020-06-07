#ifndef WINDOW_H
#define WINDOW_H
#include "sdl.hpp"
#include <iostream>

class Window
{
    public:
        Window (const int width, const int height, const std::string& title);

        bool destroy();
        bool blit(SDL_Surface* surface, const int x, const int y, const double scale);

        void render();
        void clear();
        SDL_Renderer* get_renderer();

    private:
        SDL_Window *sdl_window;
        SDL_Renderer* w_renderer;
};

#endif /* WINDOW_H */
