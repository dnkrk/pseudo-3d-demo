#include "media.hpp"
#include "texture.hpp"
#include "log.hpp"

#include <iostream>
#include <map>


Media::Media(SDL_Renderer* renderer)
{
    m_renderer = renderer;
    m_spritesheet = NULL;
};


Media::~Media()
{
    //spritesheet->free();
};


bool Media::load_assets()
{
    bool success = true;

    Texture* spritesheet = new Texture(m_renderer);

    // TODO get this image into the binary during compiling somehow
    if ( !spritesheet->load_from_file("src/sprites.png") )
    {
        Log::error("Failed to load the sprite atlas.");
        delete spritesheet;
        success = false;
    } 
    else 
    {
        m_spritesheet = spritesheet;
    }
    return true;
}


Texture* Media::get_sprite(int i)
{
    // TODO error checking
    // TODO i does nothing atm
    return m_spritesheet;
}
