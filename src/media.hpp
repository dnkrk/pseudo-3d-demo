#ifndef MEDIA_H
#define MEDIA_H

#include "sdl.hpp"
#include "texture.hpp"

#include <iostream>
#include <vector>
#include <map>


class Media
{
    public:
        Media(SDL_Renderer* renderer);
        ~Media();

        bool load_assets();
        //Texture* get_sprite(int i);
        bool render_at(int x, int y, int i, double scale=1.0, double rotation=0);
        bool render_text(int x, int y, int i);

    private:
        //std::vector<Texture*> sprites;
        Texture* spritesheet;
        SDL_Renderer* renderer;
        TTF_Font* font;
        std::vector<Texture*> text_strings;
        bool load_images();
        bool load_fonts();
        bool generate_strings();
};

#endif /* MEDIA_H */
