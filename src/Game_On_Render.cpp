#include "Game.h"

void Game::on_render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // GameTexture::on_draw(renderer, test, 0, 0);
    GameTexture::on_draw(renderer, test, 0, 0, 0, anime_king.get_current_frame() * 64, 64, 64);
    SDL_RenderPresent(renderer);
}

