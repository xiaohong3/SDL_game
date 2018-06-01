#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <SDL2/SDL.h>

#include <vector>
#include "GameAnimation.h"
#include "GameTexture.h"


class GameEntity
{
    public:
        GameEntity();
        virtual ~GameEntity();

        static std::vector<GameEntity*> entity_list;

        float x, y;
        int w, h;
        int anime_state;

        virtual bool on_load(SDL_Renderer* renderer, char* file, int w, int h, int max_frames);
        virtual void on_loop();
        virtual void on_render(SDL_Renderer* renderer);
        virtual void on_cleanup();

    protected:
        GameAnimation anim_control;
        SDL_Texture* texture;

    private:
};

#endif // GAMEENTITY_H
