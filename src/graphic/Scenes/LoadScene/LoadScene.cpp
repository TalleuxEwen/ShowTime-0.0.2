//
// Created by talleux on 4/9/24.
//

#include "LoadScene.hpp"

LoadScene::LoadScene(Core *core) : AScene(core)
{
    initScene();
}

void LoadScene::update()
{
    AScene::update();
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
        logo->setTexture(texture);
        logo->setRect(sf::IntRect(0, 0, 2000, 2250));
        logo->setPosition(sf::Vector2f((float)1920 / 2, (float)1080 / 2));
        logo->setSize(sf::Vector2f(0.5, 0.5));
        logo->setOrigin(sf::Vector2f(1000, 1125));

        addComponent(logo);
    }
}
