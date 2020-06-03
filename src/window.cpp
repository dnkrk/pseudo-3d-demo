#include "window.hpp"
#include "log.hpp"

Window::Window(const int width, const int height, const std::string& title) {

    this->sdl_window = NULL;

        this->sdl_window = SDL_CreateWindow(title.c_str(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                width,
                height,
                SDL_WINDOW_SHOWN);

        if (this->sdl_window == NULL) {
            Log::error("Could not create window");
            Log::error(SDL_GetError());
        }

    this->screen_surface = SDL_GetWindowSurface(this->sdl_window);
}

bool Window::destroy() {
    SDL_DestroyWindow(this->sdl_window);
    SDL_Quit();
    return true;
}

bool Window::blit(SDL_Surface* surface, const int x, const int y, const double scale){
    SDL_Rect test_rect;
    test_rect.x = x;
    test_rect.y = y;
    test_rect.w = 100;
    test_rect.h = 100;
    SDL_BlitScaled(surface, &test_rect, this->screen_surface, NULL);
    return true;
}

bool Window::render(){
    SDL_UpdateWindowSurface(this->sdl_window);
    return true;
}

SDL_Surface* Window::get_screen_surface(){
    return this->screen_surface;
}
