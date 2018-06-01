#include "GameAnimation.h"

GameAnimation::GameAnimation()
{
    current_frame = 0;
    max_frames = 0;
    frame_increament = 1;
    frame_rate = 100;
    old_time = 0;
    oscillate = false;
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

    old_time = SDL_GetTicks();

    // The animation is not starting from frame 0
    current_frame += frame_increament;

    if (oscillate)
    {
        if (frame_increament > 0)
        {
            if (current_frame >= (max_frames - 1))
            {
                frame_increament = -frame_increament;
            }
        }
        else
        {
            if (current_frame <= 0)
            {
                frame_increament = -frame_increament;
            }
        }
    }
    else
    {
        if (current_frame > (max_frames - 1))
        {
            current_frame = 0;
        }
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

void GameAnimation::set_frame_rate(int fr)
{
    // Too fast or too slow ignore
    if (fr < 100 || fr > 1000)
    {
        return;
    }

    frame_rate = fr;
}
