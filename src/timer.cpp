#include "timer.hpp"

Timer::Timer()
{
    this->start_ticks = 0;
    this->paused_ticks = 0;
    this->started = false;
    this->paused = false;
}


void Timer::start()
{
    this->started = true;
    this->paused = false;

    this->start_ticks = SDL_GetTicks();
    this->paused_ticks = 0;
}


void Timer::stop()
{
    this->started = false;
    this->paused = false;

    this->start_ticks = 0;
    this->paused_ticks = 0;
}


void Timer::pause()
{
    if (this->started && !this->paused)
    {
        this->paused = true;
        this->paused_ticks = SDL_GetTicks() - this->start_ticks;
        this->start_ticks = 0;
    }
}


void Timer::unpause()
{
    if (this->started && this->paused)
    {
        this->paused = false;
        this->start_ticks = SDL_GetTicks() - this->paused_ticks;
        this->paused_ticks = 0;
    }
}


uint32_t Timer::get_ticks()
{
    uint32_t time = 0;
    if (this->started)
    {
        if (this->paused)
        {
            time = this->paused_ticks;
        }
        else
        {
            time = SDL_GetTicks() - this->start_ticks;
        }
    }
    return time;
}


bool Timer::is_started()
{
    return this->started;
}


bool Timer::is_paused()
{
    return this->started && this->paused;
}
