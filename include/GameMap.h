#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include "Define.h"
#include "GameTile.h"
#include "GameTexture.h"

class GameMap
{
    public:
        GameMap();
        virtual ~GameMap();
        bool on_load(char* file);
        void on_render(SDL_Renderer* renderer, int map_x, int map_y);

        SDL_Texture* texture;

    protected:

    private:
        std::vector<GameTile> tile_list;
};

#endif // GAMEMAP_H
