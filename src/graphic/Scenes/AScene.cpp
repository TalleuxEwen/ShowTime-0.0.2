//
// Created by talleux on 4/9/24.
//

#include "AScene.hpp"

void AScene::addComponent(std::shared_ptr<IComponent> component)
{
    _components.push_back(component);
}

std::vector<std::shared_ptr<IComponent>> AScene::getComponents()
{
    return _components;
}

void AScene::display(sf::RenderWindow &window)
{
    for (auto &component : _components) {
        component->display(window);
    }
}

void AScene::update()
{
    for (auto &component : _components) {
        component->update();
    }
}

void AScene::handleEvent(const sf::Event &event, sf::RenderWindow &window)
{
    for (auto &component : _components) {
        component->handleEvent(event, window, nullptr);
    }
}

void AScene::pauseScene()
{
    for (auto &component : _components) {
        component->pause();
    }
}

void AScene::resumeScene()
{
    for (auto &component : _components) {
        component->resume();
    }
}
