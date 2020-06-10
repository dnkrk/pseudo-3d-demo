#include "sdl.hpp"
#include "game.hpp"
#include "log.hpp"
#include "window.hpp"

/*
 * TODO BUGS
 * Occasionally vehicle refuses to reverse when rapidly moving back and forth
 * Framerate still miscalculated, can't cap manually
 * guaranteed segfault on exiting game
 * turn limit not working, turning is just binary
 * Displaying over ~16 layers in a single model starts showing visual glitches
 * change to config.ini
 *
 */

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
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

    Window window(width, height, "Demo");

    Game game(&window, debug, TICKS_PER_FRAME);
    game.start();

    window.destroy();
    SDL::exit();
    return 0;
}
