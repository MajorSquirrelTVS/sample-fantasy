//
// Created by majorsquirrel on 29/09/2019.
//

#include <Sprite.hpp>

Sprite::Sprite(unsigned int index) : index(index) {}

void Sprite::attachTexture(const sf::Texture &texture) {
    size_t x, y;

    x = this->index % 48 * 16 + this->index * 1;
    y = this->index % 24 * 16 + this->index * 1;
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(x, y, 16, 16));
}

const sf::Sprite& Sprite::getSprite() const {
    return this->sprite;
}