#ifndef TILEMAPVIEW_H
#define TILEMAPVIEW_H

#include <SFML/Graphics.hpp>
// #include "TileMap.h"

class TileMap;
class TileMapView: sf::Drawable, sf::Transformable {
    const TileMap & map;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        

    }
    public:
    TileMapView(const TileMap & tileMap): map(tileMap){}
};

#endif