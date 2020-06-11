#include "game.hpp"

Game::Game(Window* window, int screen_ticks_per_frame, bool debug_mode)
{
    this->debug_mode = debug_mode;
    this->ticks_per_frame = screen_ticks_per_frame;

    this->window = window;
    this->media = new Media(this->window->get_renderer());

    this->player = new Player();
    this->world = new World(this->player, this->media);
}


Game::~Game()
{
    delete this->media;
    delete this->player;
    delete this->world;
}


void Game::start()
{
    bool quit = false;
    SDL_Event e;

    //Timer fps_timer;
    Timer cap_timer;

    int counted_frames = 0;
    //fps_timer.start();

    while (!quit){
        cap_timer.start();

        //float avg_fps = counted_frames / (fps_timer.get_ticks() / 1000.f);

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

        int frame_ticks = cap_timer.get_ticks();
        if (frame_ticks < this->ticks_per_frame)
        {
            SDL_Delay(this->ticks_per_frame - frame_ticks);
        }

        ++counted_frames;
    }
}
