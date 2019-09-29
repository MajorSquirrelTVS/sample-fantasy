//
// Created by majorsquirrel on 29/09/2019.
//

#include <Sprite.hpp>

Sprite::Sprite(unsigned int index) : m_index(index) {}

void Sprite::attachTexture(const sf::Texture &texture) {
    size_t x, y;

    x = m_index % 48 * 16 + m_index * 1;
    y = m_index % 24 * 16 + m_index * 1;
    m_sprite.setTexture(texture);
    m_sprite.setTextureRect(sf::IntRect(x, y, 16, 16));
}

sf::Sprite& Sprite::getSprite() {
    return m_sprite;
}

unsigned int Sprite::getIndex() {
    return m_index;
}