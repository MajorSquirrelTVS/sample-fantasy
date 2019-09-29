//
// Created by majorsquirrel on 29/09/2019.
//

#ifndef SAMPLE_FANTASY_SPRITE_HPP
#define SAMPLE_FANTASY_SPRITE_HPP

#include <SFML/Graphics.hpp>

class Sprite {
public:
    Sprite() = default;
    Sprite(unsigned int index);
    void attachTexture(const sf::Texture& texture);

    sf::Sprite& getSprite();
    unsigned int getIndex();
private:
    unsigned int m_index;
    sf::Sprite m_sprite;
};


#endif //SAMPLE_FANTASY_SPRITE_HPP
