#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include "sdl.hpp"
#include "log.hpp"

class Timer
{
    public:
        Timer();
        ~Timer() {}

        void start();
        void stop();
        void pause();
        void unpause();

        uint32_t get_ticks();

        bool is_started();
        bool is_paused();

    private:
        uint32_t start_ticks;
        uint32_t paused_ticks;
        bool paused;
        bool started;

};

#endif /* TIMER_H */
