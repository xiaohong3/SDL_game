#include "Game.h"

void Game::on_cleanup()
{
    SDL_DestroyTexture(test);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    test = nullptr;
    renderer = nullptr;
    window = nullptr;
    IMG_Quit();
    SDL_Quit();
}
