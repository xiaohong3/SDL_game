#ifndef GAMETEXTURE_H
#define GAMETEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GameTexture
{
    public:
        GameTexture();
        virtual ~GameTexture();
        static SDL_Texture* on_load(SDL_Renderer* renderer, const char* filename);
        static bool on_draw(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);
        static bool on_draw(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int x_, int y_, int w_, int h_);
        static void on_cleanup(SDL_Texture* texture);
};

#endif // GAMETEXTURE_H
