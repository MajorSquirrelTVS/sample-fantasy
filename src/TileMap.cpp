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
        while (std::getline(ifs, line)) {
            size_t pos = 0, row = 0;
            std::string token;

            while ((pos = line.find(',')) != std::string::npos) {
                size_t index = 0;

                token = line.substr(0, pos);
                this->map[row][index] = Sprite(std::stoi(token));
                line.erase(0, pos + 1);
                ++index;
            }

            ++row;
        }
        ifs.close();
    } else
        std::cerr << "Could not load TileMap from file correctly" << std::endl;
}

void TileMap::setTexture(const sf::Texture& texture) {
    for (size_t row = 0; row < 24; ++row) {
        for (size_t index = 0; index < 48; ++index) {
            this->map[row][index].attachTexture(texture);
        }
    }
}

void TileMap::draw(sf::RenderWindow& window) {
    for (size_t row = 0; row < 24; ++row) {
        for (size_t index = 0; index < 48; ++index) {
            window.draw(this->map[row][index].getSprite());
        }
    }
}