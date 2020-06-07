#include "sdl.hpp"
#include "log.hpp"

bool SDL::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        Log::error("SDL could not initialize");
        Log::error(SDL_GetError());
        return false;
    }
    return true;
}

void SDL::exit()
{
	SDL_Quit();
}
