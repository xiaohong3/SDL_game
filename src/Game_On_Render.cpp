#include "Game.h"

void Game::on_render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    std::vector<GameEntity*>::iterator iter;
    for (iter = GameEntity::entity_list.begin(); iter != GameEntity::entity_list.end(); ++iter)
    {
        (*iter)->on_render(renderer);
    }

    SDL_RenderPresent(renderer);
}

