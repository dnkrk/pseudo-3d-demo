#ifndef SPRITE_H_DEFINED
#define SPRITE_H_DEFINED
#include "sdl.hpp"

class Sprite {
    public:
        Sprite(const std::string& filepath);
    private:
        SDL_Surface* image;

};

#endif /* SPRITE_H_DEFINED */
