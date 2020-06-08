#include "game.hpp"

// constructor
Game::Game(Window* window, bool debug_mode)
{
    this->debug_mode = debug_mode;

    this->window = window;
    this->media = new Media(this->window->get_renderer());

    this->player = new Player();
    this->world = new World(this->player, this->media);


}

// destructor
Game::~Game()
{
    delete this->media;
    delete this->player;
    delete this->world;
}

// runs the main game loop
void Game::start()
{
    bool quit = false;
    Uint32 start_time = 0;

    SDL_Event e;

    while (!quit){
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_w:
                    this->player->go('f');
                    break;
                case SDLK_a:
                    this->player->go('l');
                    break;
                case SDLK_s:
                    this->player->go('b');
                    break;
                case SDLK_d:
                    this->player->go('r');
                    break;
                /*==== DEBUG OPTIONS =====*/
                case SDLK_r:
                    Log::debug("Resetting clock");
                    start_time = SDL_GetTicks();
                    break;
                /*== END DEBUG OPTIONS ===*/
                }
            }
        }

        this->window->clear();
        this->world->rotate_truck(1);
        this->world->render();
        this->window->render();

    }
}
