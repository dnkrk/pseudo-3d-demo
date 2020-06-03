#include "sprite.hpp"
#include "sdl.hpp"

Sprite::Sprite(const std::string& filepath) {
    this->image = SDL_LoadBMP(filepath.c_str());
}

