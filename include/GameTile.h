#ifndef GAMETILE_H
#define GAMETILE_H

enum
{
    TILE_TYPE_NONE,
    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};

class GameTile
{
    public:
        GameTile();
        virtual ~GameTile();

        int tile_id;
        int type_id;
};

#endif // GAMETILE_H
