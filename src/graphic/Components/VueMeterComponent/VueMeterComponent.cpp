//
// Created by talleux on 4/10/24.
//

#include <iostream>
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
    if (!texture.loadFromFile("../assets/vue_meter/vue_meter.jpg"))
        throw std::runtime_error("Cannot load file assets/vue_meter/vue_meter.png");
    vue->setTexture(texture);
    vue->setPosition(_position.x + 0, _position.y + 0);
    vue->setSize(sf::Vector2f(1, 1));
    vue->setAttribute("vue");
    setWidth((float)texture.getSize().x * vue->getSize().x);
    setHeight((float)texture.getSize().y * vue->getSize().y);

    sf::Texture texture2;
    if (!texture2.loadFromFile("../assets/vue_meter/fader_button.png"))
        throw std::runtime_error("Cannot load file assets/vue_meter/fader_button.png");
    auto fader = std::make_shared<SpriteComponent>(_core);
    fader->setTexture(texture2);
    fader->setSize(sf::Vector2f(1.5, 1.5));
    fader->setPosition(_position.x + (((float)texture.getSize().x / 2) - ((float)(texture2.getSize().x) * fader->getSize().x) / 2), _position.y + (float)texture.getSize().y - (float)(((float)texture2.getSize().y * fader->getSize().y) / 2));
    fader->setOpacity(75);
    fader->setAttribute("fader");

    sf::Texture texture3;
    if (!texture3.loadFromFile("../assets/vue_meter/black.jpg"))
        throw std::runtime_error("Cannot load file assets/vue_meter/black.jpg");
    auto black = std::make_shared<SpriteComponent>(_core);
    black->setTexture(texture3);
    black->setSize(sf::Vector2f(1, 1));
    black->setPosition(_position.x + 0, _position.y + 0);
    black->setOpacity(75);
    black->setAttribute("blackLeft");

    auto black2 = std::make_shared<SpriteComponent>(_core);
    black2->setTexture(texture3);
    black2->setSize(sf::Vector2f(1, 1));
    black2->setPosition(_position.x + (((float)texture.getSize().x * vue->getSize().x) / 2) , _position.y + 0);
    black2->setOpacity(75);
    black2->setAttribute("blackRight");


    addSubComponent(vue);
    addSubComponent(black);
    addSubComponent(black2);
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

void VueMeterComponent::setVolumeValues(const float *volume, int size)
{
    if (size == 1) {
        _leftVolumeValue = volume[0];
        _rightVolumeValue = volume[0];
    } else if (size == 2) {
        _leftVolumeValue = volume[0];
        _rightVolumeValue = volume[1];
    }
}

void VueMeterComponent::update()
{

    auto black = AComponent::getSubComponentByAttribute("blackLeft");
    auto black2 = AComponent::getSubComponentByAttribute("blackRight");
    auto vue = AComponent::getSubComponentByAttribute("vue");
    auto fader = AComponent::getSubComponentByAttribute("fader");

    if (black && black2 && vue && fader) {
        auto blackSprite = std::dynamic_pointer_cast<SpriteComponent>(black);
        auto blackSprite2 = std::dynamic_pointer_cast<SpriteComponent>(black2);
        auto vueSprite = std::dynamic_pointer_cast<SpriteComponent>(vue);
        auto faderSprite = std::dynamic_pointer_cast<SpriteComponent>(fader);

        float width = vueSprite->getSize().x * (float)vueSprite->getTexture().getSize().x;
        float height = vueSprite->getSize().y * (float)vueSprite->getTexture().getSize().y;

        auto calculateRatio = [this, &width, &height](float volume, const std::shared_ptr<SpriteComponent>& blackSprite) {
            float blackWidth = (float)blackSprite->getTexture().getSize().x;
            float blackHeight = (float)blackSprite->getTexture().getSize().y;

            float ratioX = width / blackWidth / 2;
            float ratioY = height / blackHeight;

            int volumePower = abs((int)volume - 100);

            ratioY = ratioY * (float)(volumePower / 100.0);

            return sf::Vector2f(ratioX, ratioY);
        };

        blackSprite->setSize(calculateRatio(_leftVolumeValue, blackSprite));
        blackSprite2->setSize(calculateRatio(_rightVolumeValue, blackSprite2));

        auto faderPosition = faderSprite->getPosition();
        auto vuePosition = vueSprite->getPosition();

        //volume is a float between 0 and 1, 0 is the bottom, 1 is the top
        _volume = std::abs((((faderPosition.y + ((float)faderSprite->getTexture().getSize().y * faderSprite->getSize().y) / 2) - vuePosition.y) / height) - 1);
    }
}

