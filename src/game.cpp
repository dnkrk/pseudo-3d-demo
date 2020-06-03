#include "game.hpp"
#include "log.hpp"
#include "media.hpp"
//TODO debug :
#include "sdl.hpp"

Game::Game(Window* window){
    this->media = new Media();
    this->media->load_assets(window->get_screen_surface());
    this->window = window;
}

Game::~Game() {
    delete this->media;
}

bool Game::start(){
    bool quit = false;
    SDL_Event e;

    while (!quit){
        // test
        SDL_Surface* s = this->media->get_sprite(5);
        if (s == NULL){
            Log::error("can't get sprite out of media");
            }
        window->blit(s, 10, 10, 1.0);
        window->render();
        // end test
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
    }
    return true;
}


