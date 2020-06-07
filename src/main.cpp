#include "sdl.hpp"
#include "game.hpp"
#include "log.hpp"
#include "window.hpp"

// TODO change to config.ini
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[]) {

    if (!SDL::init()) {
        Log::error("Could not initialize SDL");
        return 1;
    }

    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;

    Window window(width, height, "Demo");

    Game game(&window);
    game.start();

    window.destroy();
    SDL::exit();
    return 0;
}
