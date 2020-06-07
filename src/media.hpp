#ifndef MEDIA_H
#define MEDIA_H

#include "sdl.hpp"
#include "texture.hpp"

#include <iostream>
#include <map>


class Media
{
    public:
        Media(SDL_Renderer* renderer);
        ~Media();

        //Texture* get_sprite(int i);
        //bool load_assets(SDL_Renderer* renderer);
        bool load_assets();

        Texture* get_sprite(int i);

    private:
        Texture* m_spritesheet;
        SDL_Renderer* m_renderer;
};

#endif /* MEDIA_H */
