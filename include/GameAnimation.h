#ifndef GAMEANIMATION_H
#define GAMEANIMATION_H

#include <SDL2/SDL.h>

class GameAnimation
{
    public:
        GameAnimation();
        virtual ~GameAnimation();
        void set_current_frame(int frame);
        int get_current_frame();
        void on_animate();

        int max_frames;

    protected:

    private:
        int current_frame;
        int frame_increament;
        int frame_rate; // milliseconds
        long old_time;
};

#endif // GAMEANIMATION_H
