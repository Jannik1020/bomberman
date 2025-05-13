#include "Tile.h"

bool isValidTileType(int type) { return type >= TILE_BREAKABLE && type <= TILE_NONE; }

Tile::Tile(TileType type)
{
    if (isValidTileType(type))
        this->type = type;
    else
        this->type = TILE_NONE;
}