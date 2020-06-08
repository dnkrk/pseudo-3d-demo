#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

namespace SDL
{
    bool init();

    // Destroys SDL2, must be called when program terminates
    void exit();

    void load_from_rendered_text(std::string texture_text, SDL_Color color);
};

#endif /* SDL_H */
