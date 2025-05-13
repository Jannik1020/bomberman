#include <iostream>
#include "TileMap.h"

bool TileMap::placeBreakableTile(int row, int column)
{
    Tile &tile = getTileAt(row, column);
    if (tile.getTileType() != TILE_UNBREAKABLE)
    {
        tile.setTileType(TILE_BREAKABLE);
        return true;
    }
    return false;
}

bool TileMap::loadFromList(std::initializer_list<TileType> list)
{
    // check if list dimensions match map dimensions

    if (list.size() != columns * rows)
    {
        std::cerr << "TileMap::loadFromlist > initializer list of wrong dimension (" << list.size()
                  << "). Expected: " << columns << " x " << rows << " = " << columns * rows << std::endl;
        return false;
    }

    // copy list values to map
    std::vector<Tile>::iterator tile = tiles.begin();
    for (TileType type : list)
    {
        *tile = Tile(type);
        tile++;
    }

    return true;
}

bool TileMap::loadFromList(std::initializer_list<int> list)
{
    // check if list dimensions match map dimensions
    if (list.size() != columns * rows)
    {
        std::cerr << "TileMap::loadFromlist > initializer list of wrong dimension (" << list.size()
                  << "). Expected: " << columns << " x " << rows << " = " << columns * rows << std::endl;
        return false;
    }

    // copy list values as TileType to map
    std::vector<Tile>::iterator tile = tiles.begin();
    for (int type : list)
    {
        if (isValidTileType(type))
        {
            tile->setTileType(static_cast<TileType>(type));
        }
        else
        {

            // put TILE_NONE = 2 when invalid type is provided
            std::cerr << "TileMap::loadFromlist > invalid TileType int value: " << type << ". replaced it with TILE_NONE = 2" << std::endl;
            tile->setTileType(TileType::TILE_NONE);
        }

        tile++;
    }

    return true;
}

bool TileMap::loadDefault()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (row == 0 || row == rows - 1)
            {
                tiles.at(row * columns + column).setTileType(TILE_UNBREAKABLE);
                continue;
            }
            if (column == 0 || column == columns - 1)
            {
                tiles.at(row * columns + column).setTileType(TILE_UNBREAKABLE);
                continue;
            }
            if ((row) % 2 == 0 && (column) % 2 == 0)
            {
                tiles.at(row * columns + column).setTileType(TILE_UNBREAKABLE);
                continue;
            }
        }
    }
    return true;
}

const Tile &TileMap::getTileAt(int row, int column) const
{
    return tiles[row * columns + column];
    throw std::out_of_range("TileMap::getTileAt > index out of bounds");
}

Tile &TileMap::getTileAt(int row, int column)
{
    if(row * column <= rows * columns) return tiles[row * columns + column];
    throw std::out_of_range("TileMap::getTileAt > index out of bounds");
}

std::ostream &operator<<(std::ostream &os, const TileMap &map)
{
    os << "DEBUG > TileMap > operator<< > " << std::endl;
    int column = map.columns;
    for (const Tile &tile : map.tiles)
    {
        if (column == 0)
        {
            os << std::endl;
            column = map.columns;
        }
        os << tile.getTileType();
        column--;
    }
    os << std::endl;

    return os;
}