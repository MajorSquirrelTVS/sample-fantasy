//
// Created by majorsquirrel on 29/09/2019.
//

#include <fstream>
#include <iostream>

#include <TileMap.hpp>

void TileMap::loadFromFile(const std::string &path) {
    std::ifstream ifs;
    std::string line;

    ifs.open(path);
    if (ifs.is_open()) {
        size_t row = 0;

        while (std::getline(ifs, line)) {
            size_t pos = 0, index = 0;
            std::string token;

            while ((pos = line.find(',')) != std::string::npos) {
                Sprite sprite;

                token = line.substr(0, pos);
                sprite = Sprite(std::stoi(token));
                sprite.getSprite().setPosition(row * 16.0f, index * 16.0f);
                m_map.push_back(sprite);
                std::cout << "Position: " << row << ", " << index << std::endl;
                ++index;
                line.erase(0, pos + 1);
            }

            ++row;
        }
        ifs.close();
    } else
        std::cerr << "Could not load TileMap from file correctly" << std::endl;
}

void TileMap::setTexture(const sf::Texture& texture) {
    for (size_t index = 0; index < 1128; ++index) {
        m_map[index].attachTexture(texture);
    }
}

void TileMap::draw(sf::RenderWindow& window) {
    for (size_t index = 0; index < 1128; ++index) {
        window.draw(m_map[index].getSprite());
    }
}