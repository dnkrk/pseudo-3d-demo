#include "texture.hpp"
#include "log.hpp"
#include "sdl.hpp"

Texture::Texture(SDL_Renderer* renderer)
{
    t_renderer = renderer;
    t_texture = NULL;
    t_width = 0;
    t_height = 0;
    clip_width = 44;
    clip_height = 22;
    row_width = 16;
    
}


Texture::~Texture()
{
    free();
}


void Texture::free()
{
	if ( t_texture != NULL )
	{
		SDL_DestroyTexture( t_texture );
		t_texture = NULL;
		t_width = 0;
		t_height = 0;
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
        new_texture = SDL_CreateTextureFromSurface(t_renderer, new_surface);
        if (new_texture == NULL){
            Log::error("Unable convert surface to texture");
            Log::error(SDL_GetError());
        } else {
            t_width = new_surface->w;
            t_height = new_surface->h;
        }
        SDL_FreeSurface(new_surface);
    }
    t_texture = new_texture;
    return t_texture != NULL;
}


void Texture::render_clip(int x, int y, int i, double scale)
{
    SDL_Rect clip = SDL_Rect();
    clip.x = (i % row_width) * clip_width;
    clip.y = (i / row_width) * clip_height;
    clip.w = clip_width;
    clip.h = clip_height;

    render(x, y, &clip, scale);
}


void Texture::render(int x, int y, SDL_Rect* clip, double scale)
{
    SDL_Rect render_quad = {x, y, t_width, t_height};

    if (clip != NULL) {
        render_quad.w = clip->w*scale;
        render_quad.h = clip->h*scale;
    }

    if (t_renderer == NULL) {
        Log::error("Attempted to render texture with unset renderer");
    } else {
        SDL_RenderCopy(t_renderer, t_texture, clip, &render_quad);
    }
}
