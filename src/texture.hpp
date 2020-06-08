#ifndef TEXTURE_H
#define TEXTURE_H
#include "sdl.hpp"

class Texture {

    public:
        Texture(SDL_Renderer* renderer);
        ~Texture();

        void free();

        // Loads a PNG from disk
        bool load_from_file( const std::string& path );

        // Creates a rendererable text string
        bool load_from_rendered_text(std::string texture_text, SDL_Color color);

        //void set_renderer(SDL_Renderer* renderer);

        void render(int x, int y, SDL_Rect* clip=NULL, double scale=1.0, double rotation=0);
        void render_clip(int x, int y, int i, double scale=1.0, double rotation=0);

        int get_width() { return width; };
        int get_height() { return height; };
    private:
        //TODO define copy, move
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        int width;
        int height;
        int clip_width;      // The dimensions of sprites contained
        int clip_height;     //       within the sprite atlas
        int row_width;       // Sprites per row in sprite atlas

};

#endif /* TEXTURE_H */
