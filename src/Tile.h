#ifndef TILE_H
#define TILE_H

enum TileType{
        TILE_BREAKABLE,
        TILE_UNBREAKABLE,
        TILE_NONE
};


class Tile {
    TileType type;

public:
    Tile(TileType type): type(type){}
    TileType getTileType() const {return type;}
};

#endif