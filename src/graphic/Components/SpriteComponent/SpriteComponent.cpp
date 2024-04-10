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
    setWidth((float)_texture.getSize().x);
    setHeight((float)_texture.getSize().y);
}

void SpriteComponent::setPosition(sf::Vector2f position)
{
    _sprite.setPosition(position);
    _isPositionSet = true;
    _position = position;
}

void SpriteComponent::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
    _isPositionSet = true;
    _position = sf::Vector2f(x, y);
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

void SpriteComponent::setOpacity(float opacity)
{
    sf::Color color = _sprite.getColor();

    auto colorOpacity = (uint8_t)(opacity / 100 * 255);

    color.a = colorOpacity;
    _sprite.setColor(color);
}

void SpriteComponent::display(sf::RenderWindow &window)
{
    if (_isTextureSet && _isPositionSet && _isSizeSet) {
        window.draw(_sprite);
    }
}

void SpriteComponent::handleEvent(const sf::Event &event, sf::RenderWindow &window, IComponent *parentComponent)
{
    if (getAttribute() == "fader") {
        if (_sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    setIsClicked(true);
                }
            }
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                setIsClicked(false);
            }
        }
        if (event.type == sf::Event::MouseMoved) {
            auto low = parentComponent->getPosition().y + (parentComponent->getHeight() * parentComponent->getSize().y) - (((float)_texture.getSize().y * _size.y) / 2);
            auto high = parentComponent->getPosition().y - (((float)_texture.getSize().y * _size.y) / 2);
            if (getIsClicked() && (float)event.mouseMove.y < low && (float)event.mouseMove.y > high) {
                _position.y = (float)event.mouseMove.y;
                _sprite.setPosition(_position);

                //if _position.y == 365 volume is 0 and if _position.y == 0 volume is 100
                int volume = 100 - (_position.y * 100 / 365);
                //_engine->setVolume(volume);
            }
        }
    }
}

sf::Texture SpriteComponent::getTexture()
{
    return _texture;
}

void SpriteComponent::setIsClicked(bool isClicked)
{
    _isClicked = isClicked;
}

bool SpriteComponent::getIsClicked()
{
    return _isClicked;
}

