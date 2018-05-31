#include "Game.h"

void Game::on_event(SDL_Event* event)
{
    GameEvent::on_event(event);
}


void Game::on_exit()
{
    running = false;
}
