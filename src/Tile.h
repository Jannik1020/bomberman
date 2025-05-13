#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum TileType{
        TILE_BREAKABLE,
        TILE_UNBREAKABLE,
        TILE_NONE
};

constexpr static inline sf::Color mockTileTypeColors[3] = {
    sf::Color(192,192,192),
    sf::Color(96, 96, 96),
    sf::Color::Green
};

bool isValidTileType(int type);
//bool isValidTileType(TileType type) {return type >= TILE_BREAKABLE && type <= TILE_NONE;}

class Tile{
    TileType type;;

public:
    Tile(TileType type);
    TileType getTileType() const {return type;}
    void setTileType(TileType type) {
        if(isValidTileType(type)) this->type = type;
        else this->type = TILE_NONE;}
};

#endif