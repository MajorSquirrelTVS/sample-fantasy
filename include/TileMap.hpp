//
// Created by majorsquirrel on 29/09/2019.
//

#ifndef SAMPLE_FANTASY_TILEMAP_HPP
#define SAMPLE_FANTASY_TILEMAP_HPP

#include <string>

#include <Sprite.hpp>

class TileMap {
public:
    void loadFromFile(const std::string& path);
    void setTexture(const sf::Texture& texture);
    void draw(sf::RenderWindow& window);

    ~TileMap() = default;
private:
    std::vector<Sprite> m_map;
};


#endif //SAMPLE_FANTASY_TILEMAP_HPP
