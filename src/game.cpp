#include "game.hpp"

// constructor
Game::Game(Window* window, int screen_ticks_per_frame, bool debug_mode)
{
    this->debug_mode = debug_mode;

    this->window = window;
    this->media = new Media(this->window->get_renderer());

    this->player = new Player();
    this->world = new World(this->player, this->media);

    this->ticks_per_frame = screen_ticks_per_frame;
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
    SDL_Event e;

    while (!quit){
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

        }

        const Uint8* current_key_state = SDL_GetKeyboardState(NULL);
        if (current_key_state[SDL_SCANCODE_W])
        {
            this->player->go('f');
        }
        else if (current_key_state[SDL_SCANCODE_S])
        {
            this->player->go('b');
        }

        if (current_key_state[SDL_SCANCODE_A])
        {
            this->player->go('l');
        }
        else if (current_key_state[SDL_SCANCODE_D])
        {
            this->player->go('r');
        }


        this->window->clear();
        this->world->update();
        this->world->render();
        this->window->render();
    }
}
