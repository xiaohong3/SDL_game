#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <vector>
#include <SDL2/SDL.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "GameMap.h"
#include "GameTexture.h"

class GameArea
{
    public:
        GameArea();
        virtual ~GameArea();

        static GameArea area_control;
        std::vector<GameMap> map_list;

        bool on_load(SDL_Renderer* renderer, char* file);
        void on_render(SDL_Renderer* renderer, int camera_x, int camera_y);
        void on_cleanup();

    protected:

    private:
        int area_size;
        SDL_Texture* texture_tileset;

};

#endif // GAMEAREA_H
