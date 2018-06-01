#include "Game.h"

void Game::on_cleanup()
{
    std::vector<GameEntity*>::iterator iter;
    for (iter = GameEntity::entity_list.begin(); iter != GameEntity::entity_list.end(); ++iter)
    {
        (*iter)->on_cleanup();
    }

    GameEntity::entity_list.clear();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;
    IMG_Quit();
    SDL_Quit();
}
