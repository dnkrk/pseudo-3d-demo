#ifndef WINDOW_H
#define WINDOW_H
#include "sdl.hpp"
#include <iostream>

class Window
{
    public:
        Window (const int width, const int height, const int scale, const std::string& title);
        ~Window();

        bool blit(SDL_Surface* surface, const int x, const int y, const double scale);
        void generate_pattern(int x, int y);

        void render();
        void clear();
        void render_text(const std::string& text);
        SDL_Renderer* get_renderer();

    private:
        SDL_Window *sdl_window;
        SDL_Renderer* renderer;
        SDL_Texture* target_texture;
        int scale;
};

#endif /* WINDOW_H */
