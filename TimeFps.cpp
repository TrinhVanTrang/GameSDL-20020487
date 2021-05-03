#include "TimeFps.h"

TimeFps::TimeFps()
{
	start_tick_ = 0;
	paused_tick_ = 0;
	is_started_ = false;
	is_paused_ = false;
}
TimeFps::~TimeFps()
{

}

void TimeFps::start()
{
	is_started_ = true;
	is_paused_ = false;
	start_tick_ = SDL_GetTicks();

}
void TimeFps::stop()
{
	is_paused_ = false;
	is_started_ = false;

}
void TimeFps::paused()
{
	if (is_started_ == true && is_paused_ == false)
	{
		is_paused_ = true;
		paused_tick_ = SDL_GetTicks() - start_tick_;
	}
}

void TimeFps::unpaused()
{
	if (is_paused_ == true)
	{
		is_paused_ = false;
		start_tick_ = SDL_GetTicks() - paused_tick_;
		paused_tick_ = 0;
	}
}

int TimeFps::get_ticks()
{
	if (is_started_ == true)
	{
		if (is_paused_ == true)
		{
			return paused_tick_;
		}
		else
			return SDL_GetTicks() - start_tick_;
	}
	return 0;
}

bool TimeFps::is_started()
{
	return is_started_;
}
bool TimeFps::is_paused()
{
	return is_paused_;
}


