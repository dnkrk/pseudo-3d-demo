#ifndef MODEL_H_DEFINED
#define MODEL_H_DEFINED
#include "sdl.hpp"
#include <iostream>

class Model {
    public:
        Model();

    private:
        SDL_Surface* sprites[256];
};

#endif /* MODEL_H_DEFINED */
