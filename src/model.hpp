#ifndef MODEL_H
#define MODEL_H

#include "sdl.hpp"
#include <iostream>

class Model
{
    public:
        Model();

    private:
        SDL_Texture* sprites[256];
};

#endif /* MODEL_H */
