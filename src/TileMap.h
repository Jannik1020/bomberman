#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <filesystem>
#include "Tile.h"

class TileMap{
    const static int defaultColumns = 17;
    const static int defaultRows = 15;

    std::vector<Tile> tiles;

    friend std::ostream& operator<<(std::ostream& os, const TileMap& map);

    public:

    const unsigned int columns;
    const unsigned int rows;

    TileMap(unsigned int columns, unsigned int rows): columns(columns), rows(rows){
        tiles = std::vector<Tile>(rows*columns, Tile(TileType::TILE_NONE));
    }

    TileMap(): TileMap(defaultColumns, defaultRows){}

    bool placeBreakableTile(int row, int column);

    bool loadFromFile(std::filesystem::path pathToMapFile);
    bool loadFromList(std::initializer_list<TileType> list);
    bool loadFromList(std::initializer_list<int> list);
    bool loadDefault();

    const std::vector<Tile> & getRawTiles() const {return tiles;}
    const Tile & getTileAt(int row, int column) const;
    Tile & getTileAt(int row, int column);

};

#endif