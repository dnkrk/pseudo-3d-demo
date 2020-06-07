#include "window.hpp"
#include "log.hpp"

Window::Window(const int width, const int height, const std::string& title)
{

    sdl_window = NULL;
    bool failed = false;
    SDL_Renderer* new_renderer = NULL;

    sdl_window = SDL_CreateWindow(title.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_SHOWN);

    if (sdl_window == NULL) {
        Log::error("Could not create window");
        Log::error(SDL_GetError());
        failed = true;
    } else {
        //screen_surface = SDL_GetWindowSurface(sdl_window);
        new_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
        if (new_renderer == NULL) {
            Log::error("Could not create renderer");
            Log::error(SDL_GetError());
            failed = true;
        } else {
            SDL_SetRenderDrawColor(new_renderer, 0x00, 0xFF, 0xFF, 0xFF);

            int img_flags = IMG_INIT_PNG;
            if ( !(IMG_Init(img_flags) & img_flags)) {
                Log::error("Could not initialize SDL_image");
                Log::error(SDL_GetError());
                failed = true;
            }
        }
    }
    

    if (!failed) {
        w_renderer = new_renderer;
    } else {
        //TODO handle failure either here or by checking renderer in caller
    }
//screen_surface = SDL_GetWindowSurface(sdl_window);

}

bool Window::destroy()
{
    SDL_DestroyRenderer(w_renderer);
    SDL_DestroyWindow(sdl_window);
    sdl_window = NULL;
    w_renderer = NULL;
    IMG_Quit();
    SDL_Quit();
    return true;
}

bool Window::blit(SDL_Surface* surface, const int x, const int y, const double scale)
{
    SDL_Rect test_rect;
    test_rect.x = x;
    test_rect.y = y;
    test_rect.w = 100;
    test_rect.h = 100;
    //SDL_BlitScaled(surface, &test_rect, screen_surface, NULL);
    return true;
}


void Window::render()
{
    SDL_RenderPresent(w_renderer);
}


void Window::clear()
{
    //SDL_SetRenderDrawColor(w_renderer, 0, 0, 0, 0);
    SDL_SetRenderDrawColor(w_renderer, 45, 69, 36, 0);
    SDL_RenderClear(w_renderer);
}


SDL_Renderer* Window::get_renderer()
{
    return w_renderer;
}
