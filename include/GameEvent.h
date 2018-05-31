#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include <SDL2/SDL.h>

class GameEvent
{
    public:
        GameEvent();
        virtual ~GameEvent();
        virtual void on_event(SDL_Event* event);
        virtual void on_exit();
        virtual void on_key_down(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
        virtual void on_key_up(SDL_Keycode sym, Uint16 mod, Uint16 scancode);

    protected:

    private:
};

#endif // GAMEEVENT_H
