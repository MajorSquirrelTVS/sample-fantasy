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

    const sf::Sprite& getSprite() const;
private:
    unsigned int index;
    sf::Sprite sprite;
};


#endif //SAMPLE_FANTASY_SPRITE_HPP
