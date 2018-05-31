#include "Game.h"

void Game::on_render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // GameTexture::on_draw(renderer, test, 0, 0);
    GameTexture::on_draw(renderer, test, 40, 40, 0, 32, 32, 32);
    SDL_RenderPresent(renderer);
}

