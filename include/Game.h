#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameEvent.h"
#include "GameTexture.h"
#include "GameAnimation.h"

class Game : public GameEvent
{
    public:
        Game();
        virtual ~Game();
        int on_execute();
        bool on_init();
        void on_event(SDL_Event* event);
        void on_loop();
        void on_render();
        void on_cleanup();
        void on_exit();

    protected:

    private:
        bool running;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* test;
        GameAnimation anime_king;

        int WIN_W = 640;
        int WIN_H = 480;
};

#endif // GAME_H
