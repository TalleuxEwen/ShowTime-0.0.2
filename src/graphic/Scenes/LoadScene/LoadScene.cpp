//
// Created by talleux on 4/9/24.
//

#include <iostream>
#include "LoadScene.hpp"

LoadScene::LoadScene(Core *core) : AScene(core)
{
    initScene();
}

void LoadScene::update()
{
    AScene::update();
    for (auto &component : getComponents()) {
        if (component->getAttribute() == "timer") {
            auto timer = std::dynamic_pointer_cast<TimerComponent>(component);
            if (!(timer->getTargetTime().tv_sec == 0 && timer->getTargetTime().tv_usec == 0)) {
                timer->update();
                if (timer->isFinished()) {
                    timer->stop();
                    _core->getWindow(0)->changeScene("Main");
                }
            }
        }
    }
}

void LoadScene::handleEvent(const sf::Event &event, sf::RenderWindow &window)
{
    AScene::handleEvent(event, window);
}

void LoadScene::initScene()
{
    auto logo = std::make_shared<SpriteComponent>(_core);
    sf::Texture texture;
    if (!texture.loadFromFile("assets/logo.png"))
        throw std::runtime_error("Cannot load file assets/logo.png");
    else {
        logo->setAttribute("logo");
        logo->setTexture(texture);
        logo->setRect(sf::IntRect(0, 0, 2000, 2250));
        logo->setPosition(sf::Vector2f((float)1920 / 2, (float)1080 / 2));
        logo->setSize(sf::Vector2f(0.5, 0.5));
        logo->setOrigin(sf::Vector2f(1000, 1125));

        addComponent(logo);
    }

    auto timer = std::make_shared<TimerComponent>(_core);
    timer->setAttribute("timer");
    timeval target = {5, 0};
    timer->setTargetTime(target);
    timer->start();

    addComponent(timer);
}
