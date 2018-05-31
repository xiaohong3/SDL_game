#include "GameEvent.h"

GameEvent::GameEvent()
{
    //ctor
}

GameEvent::~GameEvent()
{
    //dtor
}

void GameEvent::on_event(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_QUIT:
        {
            on_exit();
            break;
        }

        case SDL_KEYDOWN:
        {
            on_key_down(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.scancode);
            break;
        }

        case SDL_KEYUP:
        {
            on_key_up(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.scancode);
            break;
        }
    }
}

void GameEvent::on_exit()
{

}

void GameEvent::on_key_down(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{

}

void GameEvent::on_key_up(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{

}
