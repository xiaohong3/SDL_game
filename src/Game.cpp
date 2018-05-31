#include "Game.h"

Game::Game()
{
    window = nullptr;
    renderer = nullptr;
    test = nullptr;

    running = true;
}

int Game::on_execute()
{
    if (on_init() == false)
    {
        return -1;
    }

    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            on_event(&event);
        }

        on_loop();
        on_render();
    }

    on_cleanup();
    return 0;
}

int main()
{
    Game game;
    return game.on_execute();
}

Game::~Game()
{
    //dtor
}
