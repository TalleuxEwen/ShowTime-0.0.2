//
// Created by talleux on 4/9/24.
//

#include <iostream>
#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(Core *core) : AComponent(core)
{
    _sprite = sf::Sprite();
    _isTextureSet = false;
    _isPositionSet = false;
    _isSizeSet = false;
}

void SpriteComponent::setTexture(const sf::Texture &texture)
{
    _texture = texture;
    _sprite.setTexture(_texture);
    _isTextureSet = true;
}

void SpriteComponent::setPosition(sf::Vector2f position)
{
    _sprite.setPosition(position);
    _isPositionSet = true;
}

void SpriteComponent::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
    _isPositionSet = true;
}

void SpriteComponent::setSize(sf::Vector2f size)
{
    _size = size;
    _sprite.setScale(_size);
    _isSizeSet = true;
}

void SpriteComponent::setRect(sf::IntRect rect)
{
    _sprite.setTextureRect(rect);
}

void SpriteComponent::setOrigin(sf::Vector2f origin)
{
    _sprite.setOrigin(origin);
}

void SpriteComponent::display(sf::RenderWindow &window)
{
    if (_isTextureSet && _isPositionSet && _isSizeSet) {
        window.draw(_sprite);
    }
}

void SpriteComponent::handleEvent(const sf::Event &event, sf::RenderWindow &window)
{
    (void)event;
    (void)window;
}

sf::Texture SpriteComponent::getTexture()
{
    return _texture;
}

