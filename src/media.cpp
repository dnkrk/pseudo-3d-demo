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
    delete &this->spritesheet;
    this->spritesheet = nullptr;

    delete[] &this->text_strings;

    TTF_CloseFont(this->font);
    this->font = nullptr;
};


bool Media::load_assets()
{
    return load_images() && load_fonts();
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


bool Media::load_fonts()
{
    bool success = true;
    this->font = TTF_OpenFont("font.ttf", 28);
    if (this->font == nullptr)
    {
        Log::error("Failed to load the sprite atlas.");
        success = false;
    }
    else
    {
        SDL_Color color = {0,0,0};
        Texture* test_texture = new Texture(this->renderer);
        if (!test_texture->load_from_rendered_text("ABCdef123!@#", color))
        {
            Log::error("Unable to render text textures.");
            success = false;
        }
        delete test_texture;
    }
    return success;
}


bool Media::render_at(int x, int y, int i, double scale, double rotation)
{
    this->spritesheet->render_clip(x, y, i, scale, rotation);
}

bool Media::render_text(int x, int y, int i)
{
    if (!(i >= 0 && i < this->text_strings.size())) { return false; }
    this->text_strings[i]->render(x, y);
}


bool Media::generate_strings()
{
    std::vector<std::string> strings = {
        "Hello world",
        "And another one"
    };
    SDL_Color color = {0,0,0};

    for (auto s : strings)
    {
        Texture* txt = new Texture(this->renderer);
        txt->load_from_rendered_text(s, color);
        this->text_strings.push_back(txt);
    }
    //TODO
    return true;
}
