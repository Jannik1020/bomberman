#ifndef TILEMAPVIEW_H
#define TILEMAPVIEW_H

#include <SFML/Graphics.hpp>
#include "TileMap.h"

class TileMapView: public sf::Drawable, public sf::Transformable {
    const TileMap & map;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    public:
    const static int width = 64;
    const static int height = 64;
    TileMapView(const TileMap & tileMap): map(tileMap){}
};

#endif