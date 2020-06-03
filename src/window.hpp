#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED
#include "sdl.hpp"
#include <iostream>

class Window {
    public:
        Window (const int width, const int height, const std::string& title);
        bool blit(SDL_Surface* surface, const int x, const int y, const double scale);
        bool destroy();
        bool render();
        SDL_Surface* get_screen_surface();
    private:
        SDL_Window* sdl_window;
        SDL_Surface* screen_surface;
};

#endif /* WINDOW_H_DEFINED */

