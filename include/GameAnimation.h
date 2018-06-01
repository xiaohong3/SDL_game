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
        void set_frame_rate(int fr);

        int max_frames;
        bool oscillate;

    protected:

    private:
        int current_frame;
        int frame_increament;
        int frame_rate; // milliseconds
        long old_time;
};

#endif // GAMEANIMATION_H
