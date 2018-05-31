#include "GameTexture.h"

GameTexture::GameTexture()
{
    //ctor
}

GameTexture::~GameTexture()
{
    //dtor
}

SDL_Texture* GameTexture::on_load(SDL_Renderer* renderer, const char* filename)
{
    SDL_Texture* texture = nullptr;
    SDL_Surface* temp_surface = IMG_Load(filename);

    if (temp_surface == nullptr)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError());
        return texture;
    }

    texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
    if (texture == nullptr)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", filename, SDL_GetError());
    }

    SDL_FreeSurface(temp_surface);
    return texture;
}

bool GameTexture::on_draw(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y)
{
    SDL_Rect dst_r;

    dst_r.x = x;
    dst_r.y = y;
    SDL_QueryTexture(texture, nullptr, nullptr, &dst_r.w, &dst_r.h);
    SDL_RenderCopy(renderer, texture, nullptr, &dst_r);
    return true;
}

bool GameTexture::on_draw(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int x_, int y_, int w_, int h_)
{
    SDL_Rect src_r = { x_, y_, w_, h_ };
    SDL_Rect dst_r = { x, y, w_, h_ };
    SDL_RenderCopy(renderer, texture, &src_r, &dst_r);
    return true;
}
