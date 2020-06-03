#ifndef SDL_H_DEFINED
#define SDL_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

namespace SDL {
    bool init();

    // Destroys SDL2, must be called when program terminates
    void exit();
};

#endif /* SDL_H_DEFINED */
