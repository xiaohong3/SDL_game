#include "Game.h"

void Game::on_loop()
{
    std::vector<GameEntity*>::iterator iter;
    for (iter = GameEntity::entity_list.begin(); iter != GameEntity::entity_list.end(); ++iter)
    {
        (*iter)->on_loop();
    }
}
