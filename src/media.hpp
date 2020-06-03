#ifndef MEDIA_H_DEFINED
#define MEDIA_H_DEFINED

#include "sdl.hpp"
#include "sprite.hpp"
#include <iostream>
#include <map>


class Media {
    public:
        Media();
        SDL_Surface* get_sprite(int i);
        bool load_assets(SDL_Surface* screen_surface);

    private:
        SDL_Surface* sprites[256];
};

#endif /* MEDIA_H_DEFINED */
