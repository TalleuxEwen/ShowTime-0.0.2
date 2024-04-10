//
// Created by talleux on 4/10/24.
//

#include "MainScene.hpp"

MainScene::MainScene(Core *core) : AScene(core)
{
    initScene();
}

void MainScene::initScene()
{
    auto vueMeter = std::make_shared<VueMeterComponent>(_core);
    vueMeter->VueMeterComponent::setPosition((sf::Vector2f){1500, 400});
    vueMeter->VueMeterComponent::setSize((sf::Vector2f){0.5, 0.5});
    addComponent(vueMeter);

    auto vueMeter2 = std::make_shared<VueMeterComponent>(_core);
    vueMeter2->VueMeterComponent::setPosition((sf::Vector2f){100, 200});
    vueMeter2->VueMeterComponent::setSize((sf::Vector2f){0.75, 0.75});
    addComponent(vueMeter2);

    auto vueMeter3 = std::make_shared<VueMeterComponent>(_core);
    vueMeter3->VueMeterComponent::setPosition((sf::Vector2f){1000, 800});
    vueMeter3->VueMeterComponent::setSize((sf::Vector2f){0.25, 0.25});
    addComponent(vueMeter3);

    auto vueMeter4 = std::make_shared<VueMeterComponent>(_core);
    vueMeter4->VueMeterComponent::setPosition((sf::Vector2f){500, 500});
    vueMeter4->VueMeterComponent::setSize((sf::Vector2f){0.5, 0.5});
    addComponent(vueMeter4);
}

void MainScene::update()
{
    AScene::update();
}

void MainScene::handleEvent(const sf::Event &event, sf::RenderWindow &window)
{
    AScene::handleEvent(event, window);
}
