#include "game.hpp"

// constructor
Game::Game(Window* window)
{
    g_window = window;
    g_media = new Media(g_window->get_renderer());
    g_media->load_assets();

    g_world = new World();
}

// destructor
Game::~Game()
{
    delete g_media;
    delete g_world;
}

// runs the main game loop
void Game::start()
{
    bool quit = false;
    SDL_Event e;

    while (!quit){
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_w:
                    Log::debug("pressed W");
                    break;
                case SDLK_s:
                    Log::debug("pressed s");
                    break;
                case SDLK_a:
                    Log::debug("pressed a");
                    break;
                case SDLK_d:
                    Log::debug("pressed d");
                    break;
                }
            }
        }

        g_window->clear();
        Texture* s = g_media->get_sprite(0);
        s->render_clip(0, 0, 1, 5.0);
        g_window->render();

    }
}
