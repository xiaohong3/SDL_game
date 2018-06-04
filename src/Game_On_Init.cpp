#include "Game.h"

bool Game::on_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    window = SDL_CreateWindow("SDL game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    if (entity1.on_load(renderer, "gfx/yoshi.png", 64, 64, 8) == false)
    {
        return false;
    }

    if (entity2.on_load(renderer, "gfx/yoshi.png", 64, 64, 8) == false)
    {
        return false;
    }

    entity2.x = 100;

    GameEntity::entity_list.push_back(&entity1);
    GameEntity::entity_list.push_back(&entity2);

    GameMap map;
    map.on_load("maps/1.map");

    return true;
}
