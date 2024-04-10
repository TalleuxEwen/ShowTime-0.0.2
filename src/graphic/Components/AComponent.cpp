//
// Created by talleux on 4/9/24.
//

#include "AComponent.hpp"

void AComponent::display(sf::RenderWindow &window)
{
    (void)window;
}

void AComponent::handleEvent(const sf::Event &event, sf::RenderWindow &window, IComponent *parentComponent)
{
    (void)event;
    (void)window;
    (void)parentComponent;
}

void AComponent::update()
{
}

void AComponent::pause()
{
}

void AComponent::resume()
{
}

void AComponent::addSubComponent(std::shared_ptr<IComponent> component)
{
    _subComponents.push_back(component);
}

std::vector<std::shared_ptr<IComponent>> AComponent::getSubComponents()
{
    return _subComponents;
}

void AComponent::setAttribute(const std::string &attribute)
{
    _attribute = attribute;
}

std::string AComponent::getAttribute() const
{
    return _attribute;
}

void AComponent::setPosition(const sf::Vector2f &position)
{
    _position = position;
}

sf::Vector2f AComponent::getPosition() const
{
    auto pos = _position;
    return pos;
}

void AComponent::setSize(const sf::Vector2f &size)
{
    _size = size;
}

sf::Vector2f AComponent::getSize() const
{
    return _size;
}

float AComponent::getHeight() const
{
    return _height;
}

void AComponent::setHeight(float height)
{
    _height = height;
}

float AComponent::getWidth() const
{
    return _width;
}

void AComponent::setWidth(float width)
{
    _width = width;
}

std::shared_ptr<IComponent> AComponent::getSubComponentByAttribute(const std::string &attribute)
{
    for (auto &component : _subComponents) {
        if (component->getAttribute() == attribute) {
            return component;
        }
    }
    return nullptr;
}
