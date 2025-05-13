#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <filesystem>
#include "Tile.h"

class TileMap{
    const static int defaultColumns = 17;
    const static int defaultRows = 15;

    std::vector<Tile> tiles;
    unsigned int columns;
    unsigned int rows;

    friend std::ostream& operator<<(std::ostream& os, const TileMap& map);

    public:
    TileMap(unsigned int columns, unsigned int rows): columns(columns), rows(rows){
        tiles = std::vector<Tile>(rows*columns, Tile(TileType::TILE_NONE));
    }

    TileMap(): TileMap(defaultColumns, defaultRows){}

    bool loadFromFile(std::filesystem::path pathToMapFile);
    bool loadFromList(std::initializer_list<TileType> list);
    bool loadFromList(std::initializer_list<int> list);
    bool loadDefault();

};

#endif