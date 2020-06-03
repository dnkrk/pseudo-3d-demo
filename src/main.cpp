#include "sdl.hpp"
#include "game.hpp"
#include "window.hpp"

// TODO change to config.ini
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const bool DEBUG = true;


int main(int argc, char* args[]) {

    if (!SDL::init()) {
        // TODO graceful exit bitte
        return 1;
    }

    // TODO update as above
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;

    Window window(width, height, "Demo");
    Game game(&window);
    game.start();

    window.destroy();
    SDL::exit();
}
