#include "GameEntity.h"

std::vector<GameEntity*> GameEntity::entity_list;

GameEntity::GameEntity()
{
    texture = nullptr;
    x = y= 0.0f;
    w = h = 0;
    anime_state = 0;
}

GameEntity::~GameEntity()
{
    //dtor
}

bool GameEntity::on_load(SDL_Renderer* renderer, char* file, int w, int h, int max_frames)
{
    texture = GameTexture::on_load(renderer, file);

    if (texture == nullptr)
    {
        return false;
    }

    this->w = w;
    this->h = h;
    anim_control.max_frames = max_frames;

    return true;
}

void GameEntity::on_loop()
{
    anim_control.on_animate();
}

void GameEntity::on_render(SDL_Renderer* renderer)
{
    if (texture == nullptr || renderer == nullptr)
    {
        return;
    }

    GameTexture::on_draw(renderer, texture, x, y, anime_state * w, anim_control.get_current_frame() * h, w, h);
}

void GameEntity::on_cleanup()
{
    GameTexture::on_cleanup(texture);
}
