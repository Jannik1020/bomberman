#include "TileMapView.h"

void TileMapView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    const std::vector<Tile> &tiles = map.getRawTiles();

    sf::VertexArray vertices;

    vertices.setPrimitiveType(sf::PrimitiveType::TriangleStrip);
    vertices.resize(4);

    for (int row = 0; row < map.rows; row++)
    {
        for (int column = 0; column < map.columns; column++)
        {

            int xOffset = column * width;
            int yOffset = row * height;

            vertices[0].position = sf::Vector2f(xOffset, yOffset);
            vertices[1].position = sf::Vector2f(xOffset, yOffset + height);
            vertices[2].position = sf::Vector2f(xOffset + width, yOffset);
            vertices[3].position = sf::Vector2f(xOffset + width, yOffset + height);

            vertices[0].color =
                vertices[1].color =
                    vertices[2].color =
                        vertices[3].color = mockTileTypeColors[tiles.at(row * map.columns + column).getTileType()];

            target.draw(vertices, states);
        }
    }
}