#include "media.hpp"
#include "log.hpp"
#include <iostream>
#include <map>


Media::Media() {
};

bool Media::load_assets(SDL_Surface* screen_surface) {
    // Load the sprite atlas
    //std::string filepath = "sprites.bmp";

    const int NUM_SPRITES = 16;  // TODO change to spritesheet
    for (int i=1; i <= NUM_SPRITES; ++i){
        std::string filepath = "sprites/" + std::to_string(i) + ".bmp";
        SDL_Surface* raw_image = SDL_LoadBMP(filepath.c_str());
        SDL_Surface* optimized_image = SDL_ConvertSurface(raw_image, screen_surface->format, 0);
        SDL_FreeSurface(raw_image);
        if (optimized_image == NULL){
            Log::error("Unable to load or optimize image");
            Log::error(filepath);
        }
        sprites[i] = optimized_image;
    }

}

SDL_Surface* Media::get_sprite(int i) {
    // TODO error checking
    return this->sprites[i];
}
