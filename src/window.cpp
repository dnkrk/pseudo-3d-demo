#include "window.hpp"
#include "log.hpp"

Window::Window(const int width, const int height, const int scale, const std::string& title)
{

    this->scale = scale;

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
        new_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);
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

            if (TTF_Init() == -1) {
                Log::error("Could not initialize SDL_TTF");
                Log::error(TTF_GetError());
                failed = true;
            }
        }
    }
    

    // Window texture
    SDL_Texture* new_texture = SDL_CreateTexture(new_renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, 
            width*scale,
            height*scale);

    if (!failed) {
        this->renderer = new_renderer;
        this->target_texture = new_texture;
    } else {
        //TODO handle failure either here or by checking renderer in caller
    }
//screen_surface = SDL_GetWindowSurface(sdl_window);

}


Window::~Window()
{
    SDL_DestroyRenderer(this->renderer);

    SDL_DestroyWindow(sdl_window);
    sdl_window = nullptr;
    this->renderer = nullptr;

    SDL_DestroyTexture(this->target_texture);
    this->target_texture = nullptr;

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
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
    SDL_RenderPresent(this->renderer);
}


void Window::clear()
{
    //SDL_SetRenderDrawColor(w_renderer, 0, 0, 0, 0);
    SDL_SetRenderDrawColor(this->renderer, 45, 69, 36, 0);
    SDL_RenderClear(this->renderer);
}


SDL_Renderer* Window::get_renderer()
{
    return this->renderer;
}


void Window::render_text(const std::string& text)
{

}
