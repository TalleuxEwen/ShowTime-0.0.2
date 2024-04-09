//
// Created by talleux on 4/9/24.
//

#include "AComponent.hpp"

void AComponent::display(sf::RenderWindow &window)
{
    (void)window;
}

void AComponent::handleEvent(const sf::Event &event, sf::RenderWindow &window)
{
    (void)event;
    (void)window;
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
