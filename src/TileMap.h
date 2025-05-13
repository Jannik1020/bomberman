#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <filesystem>
#include "Tile.h"

class TileMap{
    std::vector<Tile> tiles;
    unsigned int columns;
    unsigned int rows;

    public:
    TileMap(unsigned int columns, unsigned int rows): columns(columns), rows(rows){
        tiles = std::vector<Tile>(rows*columns, Tile(TileType::TILE_NONE));
    }
    bool loadFromFile(std::filesystem::path pathToMapFile);
};

#endif