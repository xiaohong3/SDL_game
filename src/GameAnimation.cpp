#include "GameAnimation.h"

GameAnimation::GameAnimation()
{
    current_frame = 0;
    max_frames = 4;
    frame_increament = 1;
    frame_rate = 1000;
    old_time = 0;
}

GameAnimation::~GameAnimation()
{
    //dtor
}

void GameAnimation::on_animate()
{
    if (old_time + frame_rate > SDL_GetTicks())
    {
        return;
    }

    current_frame += frame_increament;

    if (current_frame >= (max_frames -1))
    {
        current_frame = 0;
    }
}

void GameAnimation::set_current_frame(int frame)
{
    if (frame < 0 || frame >= max_frames)
    {
        return;
    }

    current_frame = frame;
}

int GameAnimation::get_current_frame()
{
    return current_frame;
}
