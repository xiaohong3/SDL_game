#include "GameArea.h"

GameArea GameArea::area_control;

GameArea::GameArea()
{
    area_size = 0;
}

GameArea::~GameArea()
{
    //dtor
}

bool GameArea::on_load(SDL_Renderer* renderer, char* file)
{
    map_list.clear();
    std::ifstream ifs;
    ifs.open(file, std::ios_base::in);

    if (!ifs)
    {
        return false;
    }

    std::string tileset_file;

    ifs >> tileset_file;

    texture_tileset = GameTexture::on_load(renderer, tileset_file.c_str());

    if (texture_tileset == nullptr)
    {
        ifs.close();
        return false;
    }

    ifs >> area_size;

    for (int y = 0; y < area_size; ++y)
    {
        for (int x = 0; x < area_size; ++x)
        {
            std::string map_file;
            ifs >> map_file;

            GameMap temp_map;

            if (temp_map.on_load(map_file.c_str() == false))
            {
                ifs.close();
                return false;
            }

            temp_map.texture = texture_tileset;
            map_list.push_back(temp_map);
        }
    }

    ifs.close();
    return true;
}
