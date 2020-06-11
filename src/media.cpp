#include "media.hpp"
#include "texture.hpp"
#include "log.hpp"

#include <iostream>
#include <map>


Media::Media(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    load_assets();
};


Media::~Media()
{
    delete this->spritesheet;
    this->spritesheet = nullptr;
};


bool Media::load_assets()
{
    return load_images();
}


bool Media::load_images()
{
    bool success = true;
    Texture* new_spritesheet = new Texture(this->renderer);
    // TODO get this image into the binary during compiling somehow
    if ( !new_spritesheet->load_from_file("src/sprites.png") )
    {
        Log::error("Failed to load the sprite atlas.");
        success = false;
    } 
    else 
    {
        this->spritesheet = new_spritesheet;
    }

    return success;
}


bool Media::render_at(int x, int y, int i, double scale, double rotation)
{
    this->spritesheet->render_clip(x, y, i, scale, rotation);
    return true;
}
