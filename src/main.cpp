#include "sdl.hpp"
#include "game.hpp"
#include "log.hpp"
#include "window.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
const int SCALE = 5;
const int SCREEN_FPS = 60;
const int TICKS_PER_FRAME = 1000/SCREEN_FPS;
const bool DEBUG_MODE = true;


int main(int argc, char* args[]) {

    if (!SDL::init()) {
        Log::error("Could not initialize SDL");
        return 1;
    }

    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;
    bool debug = DEBUG_MODE;

    Window window(width, height, SCALE, "Demo");

    Game game(&window, TICKS_PER_FRAME, debug);
    game.start();

    SDL::exit();
    return 0;
}
