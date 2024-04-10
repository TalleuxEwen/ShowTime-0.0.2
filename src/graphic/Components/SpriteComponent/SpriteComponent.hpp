//
// Created by talleux on 4/9/24.
//

#pragma once

#include "../AComponent.hpp"
#include "../../../core/Core.hpp"

class Core;

class SpriteComponent : public AComponent
{
    public:
        /**
         * @brief SpriteComponent, constructor of SpriteComponent
         */
        explicit SpriteComponent(Core *core);

        /**
         * @brief ~SpriteComponent, destructor of SpriteComponent
         */
        ~SpriteComponent() override = default;

        /**
         * @brief setTexture, set the texture
         * @param texture
         */
        void setTexture(const sf::Texture &texture);

        /**
         * @brief setPosition, set the position
         * @param position
         */
        void setPosition(sf::Vector2f position);

        /**
         * @brief setPosition, set the position
         * @param x
         * @param y
         */
        void setPosition(float x, float y);

        /**
         * @brief setSize, set the size
         * @param size
         */
        void setSize(sf::Vector2f size);

        /**
         * @brief setRect, set the rect
         * @param rect
         */
        void setRect(sf::IntRect rect);

        /**
         * @brief setOrigin, set the origin
         * @param origin
         */
        void setOrigin(sf::Vector2f origin);

        /**
         * @brief setOpacity, set the opacity
         * @param opacity
         */
        void setOpacity(float opacity);

/**
         * @brief display, display the sprite
         * @param window
         */
        void display(sf::RenderWindow &window) override;

        /**
         * @brief handleEvent, handle the event
         * @param event
         * @param window
         */
        void handleEvent(const sf::Event &event, sf::RenderWindow &window, IComponent *parentComponent) override;

        /**
         * @brief getTexture, get the texture
         * @return sf::Texture
         */
        sf::Texture getTexture();

        /**
         * @brief setIsClicked, set the isClicked
         * @param isClicked
         */
        void setIsClicked(bool isClicked);

        /**
         * @brief getIsClicked, get the isClicked
         * @return bool
         */
        bool getIsClicked();

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::IntRect _rect;
        bool _isTextureSet;
        bool _isPositionSet;
        bool _isSizeSet;
        bool _isClicked{};

};
