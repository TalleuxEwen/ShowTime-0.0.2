//
// Created by talleux on 4/10/24.
//

#include "VueMeterComponent.hpp"

VueMeterComponent::VueMeterComponent(Core *core) : AComponent(core)
{
    init();
}

void VueMeterComponent::init()
{
    setAttribute("vue_meter");
    setPosition(0, 0);
    auto vue = std::make_shared<SpriteComponent>(_core);
    sf::Texture texture;
    if (!texture.loadFromFile("assets/vue_meter/vue_meter.jpg"))
        throw std::runtime_error("Cannot load file assets/vue_meter/vue_meter.png");
    vue->setTexture(texture);
    vue->setPosition(_position.x + 0, _position.y + 0);
    vue->setSize(sf::Vector2f(1, 1));
    setWidth((float)texture.getSize().x * vue->getSize().x);
    setHeight((float)texture.getSize().y * vue->getSize().y);

    sf::Texture texture2;
    if (!texture2.loadFromFile("assets/vue_meter/fader_button.png"))
        throw std::runtime_error("Cannot load file assets/vue_meter/fader_button.png");
    auto fader = std::make_shared<SpriteComponent>(_core);
    fader->setTexture(texture2);
    fader->setSize(sf::Vector2f(1.5, 1.5));
    fader->setPosition(_position.x + (((float)texture.getSize().x / 2) - ((float)(texture2.getSize().x) * fader->getSize().x) / 2), _position.y + (float)texture.getSize().y - (float)(((float)texture2.getSize().y * fader->getSize().y) / 2));
    fader->setOpacity(75);
    fader->setAttribute("fader");


    addSubComponent(vue);
    addSubComponent(fader);
}

void VueMeterComponent::setPosition(sf::Vector2f position)
{
    for (auto &component : _subComponents) {
        auto sprite = std::dynamic_pointer_cast<SpriteComponent>(component);
        if (sprite) {
            sprite->setPosition((sf::Vector2f) {sprite->getPosition().x - _position.x, sprite->getPosition().y - _position.y});
        }
    }
    _position = position;
    for (auto &component : _subComponents) {
        auto sprite = std::dynamic_pointer_cast<SpriteComponent>(component);
        if (sprite)
            sprite->setPosition((sf::Vector2f){position.x + sprite->getPosition().x, position.y + sprite->getPosition().y});
    }
}

void VueMeterComponent::setPosition(float x, float y)
{
    _position = sf::Vector2f(x, y);
}

void VueMeterComponent::setSize(sf::Vector2f size)
{
    _size = size;
    for (auto &component : _subComponents) {
        auto sprite = std::dynamic_pointer_cast<SpriteComponent>(component);
        if (sprite) {
            sprite->setSize((sf::Vector2f) {sprite->getSize().x * size.x, sprite->getSize().y * size.y});
            sprite->setPosition((sf::Vector2f) {(sprite->getPosition().x - _position.x) * size.x + _position.x, (sprite->getPosition().y - _position.y) * size.y + _position.y});
        }
    }
}

void VueMeterComponent::display(sf::RenderWindow &window)
{
    for (auto &component : _subComponents) {
        component->display(window);
    }
}

void VueMeterComponent::handleEvent(const sf::Event &event, sf::RenderWindow &window, IComponent *parentComponent)
{
    for (auto &component : _subComponents) {
        component->handleEvent(event, window, this);
    }
}

