#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Bomberman");
    window.setFramerateLimit(144);

    sf::Texture texture("src/sprites/gnome_blue.png");
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
        window.draw(sprite);
        window.display();
    }
}
