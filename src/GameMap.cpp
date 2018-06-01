#include "GameMap.h"

GameMap::GameMap()
{
    texture = nullptr;
}

GameMap::~GameMap()
{
    //dtor
}

bool GameMap::on_load(char* file)
{
    tile_list.clear();

    File* file_handle = fopen(file, "r");

    if (file_handle == nullptr)
    {
        return false;
    }

    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            GameTile tile;
            fscanf(file_handle, "%d:%d ", &tile.tile_id, &tile.type_id);
            tile_list.push_back(tile);
        }
        fscanf(file_handle, "\n");
    }

    fclose(file_handle);

    return true;
}

void GameMap::on_render(SDL_Renderer* renderer, int map_x, int map_y)
{
    if (texture == nullptr)
    {
        return;
    }

    int tile_texture_w = 0;
    int tile_texture_h = 0;

    SDL_QueryTexture(texture, nullptr, -1, &tile_texture_w, &tile_texture_h);

    int tile_set_w = tile_texture_w / TILE_SIZE;
    int tile_set_h = tile_set_h / TILE_SIZE;

    int id = 0;

    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (tile_list[id].type_id == TILE_TYPE_NONE)
            {
                ++id;
                continue;
            }

            int tX = map_x + x * TILE_SIZE;
            int tY = map_y + y * TILE_SIZE;

            int tile_set_x = (tile_list[id].type_id % tile_set_w) * TILE_SIZE;
            int tile_set_y = (tile_list[id].type_id / tile_set_w) * TILE_SIZE;

            GameTexture::on_draw(renderer, texture, tX, tY, tile_set_x, tile_set_y, TILE_SIZE, TILE_SIZE);
            ++id;
        }
    }
}
