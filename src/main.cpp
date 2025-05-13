#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"
#include "TileMapView.h"

int main(int argc, char *argv[])
{
    std::filesystem::path pathToSprites("../resources/sprites/");

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Bomberman");
    window.setFramerateLimit(144);

    TileMap map;
    map.loadDefault();
    map.placeBreakableTile(1, 5);
    map.placeBreakableTile(1, 6);
    map.placeBreakableTile(3, 9);
    
    std::cout << map;

    TileMapView mapView(map);

    sf::Texture texture(pathToSprites.concat("gnome_blue.png"));
    sf::Sprite sprite(texture);
    sprite.setScale(sf::Vector2f(10,10));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        // window.draw(sprite);
        window.draw(mapView);
        window.display();
    }
}
