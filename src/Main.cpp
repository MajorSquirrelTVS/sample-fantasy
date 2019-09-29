#include <iostream>

#include <SFML/Graphics.hpp>
#include <TileMap.hpp>

int main(int ac, char** av) {
    sf::RenderWindow window;
    sf::Texture texture;
    TileMap tileMap;

    window.create(sf::VideoMode(768, 384), "sample_fantasy");
    if (!texture.loadFromFile("../resources/1bitpack_kenney/Tilesheet/colored.png")) {
        std::cerr << "Could not load texture file from path: resources/1bitpack_kenney/Sample_fantasy.png" << std::endl;
        window.close();
    }

    tileMap.loadFromFile("../resources/1bitpack_kenney/Tilemap/sample_fantasy.csv");
    tileMap.setTexture(texture);
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        tileMap.draw(window);
        window.display();
    }

    return 0;
}