#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Define.h"

#include <vector>
#include "GameEvent.h"
#include "GameEntity.h"
#include "GameMap.h"

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

        GameEntity entity1;
        GameEntity entity2;
};

#endif // GAME_H
