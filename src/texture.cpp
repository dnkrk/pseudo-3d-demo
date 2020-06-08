#include "texture.hpp"
#include "log.hpp"
#include "sdl.hpp"

Texture::Texture(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->texture = NULL;
    this->width = 0;
    this->height = 0;
    this->clip_width = 44;
    this->clip_height = 22;
    this->row_width = 8;
    
}


Texture::~Texture()
{
    free();
}


void Texture::free()
{
	if ( this->texture != NULL )
	{
		SDL_DestroyTexture( this->texture );
		this->texture = NULL;
		this->width = 0;
		this->height = 0;
	}

}


bool Texture::load_from_file( const std::string& path )
{
    // Deallocate existing
    free();

    SDL_Texture* new_texture = NULL;
    SDL_Surface* new_surface = IMG_Load(path.c_str());

    if (new_surface == NULL)
    {
        Log::error("Unable to load asset");
        Log::error(IMG_GetError());
    }
    else
    {
        SDL_SetColorKey( new_surface, SDL_TRUE, SDL_MapRGB(new_surface->format, 0xFF, 0, 0xFF));
        new_texture = SDL_CreateTextureFromSurface(this->renderer, new_surface);
        if (new_texture == NULL){
            Log::error("Unable convert surface to texture");
            Log::error(SDL_GetError());
        } else {
            this->width = new_surface->w;
            this->height = new_surface->h;
        }
        SDL_FreeSurface(new_surface);
    }
    this->texture = new_texture;
    return this->texture != NULL;
}


void Texture::render_clip(int x, int y, int i, double scale, double rotation)
{
    SDL_Rect clip = SDL_Rect();
    clip.x = (i % row_width) * clip_width;
    clip.y = (i / row_width) * clip_height;
    clip.w = clip_width;
    clip.h = clip_height;

    render(x, y, &clip, scale, rotation);
}


void Texture::render(int x, int y, SDL_Rect* clip, double scale, double rotation)
{
    SDL_Rect render_quad = {x, y, this->width, this->height};
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Point* center = nullptr;

    if (clip != NULL) {
        render_quad.w = clip->w*scale;
        render_quad.h = clip->h*scale;
    }

    if (this->renderer == NULL) {
        Log::error("Attempted to render texture with unset renderer");
    } else {
        SDL_RenderCopyEx(this->renderer, this->texture, clip, &render_quad, rotation, center, flip);
    }
}


bool Texture::load_from_rendered_text(std::string texture_text, SDL_Color color)
{
    this->free();
    TTF_Font* font = nullptr;
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, texture_text.c_str(), color);
    if (text_surface == nullptr)
    {
        Log::error("Unable to render text surface.");
        Log::error(TTF_GetError());
    }
    else
    {
        this->texture = SDL_CreateTextureFromSurface(this->renderer, text_surface);
        if (this->texture == nullptr) {
            Log::error("Cannot convert texture from rendered text");
            Log::error(SDL_GetError());
        }
        else
        {
            this->width = text_surface->w;
            this->height = text_surface->h;
        }

        SDL_FreeSurface(text_surface);
    }
    return (this->texture != nullptr);
}
