//
// Created by talleux on 4/9/24.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Core;

class IComponent
{
    public:
        /**
         * @brief IComponent, constructor of IComponent
         */
        explicit IComponent(Core *core) : _core(core) {}

        /**
         * @brief ~IComponent, destructor of IComponent
         */
        virtual ~IComponent() = default;

        /**
         * @brief display, display the component
         */
        virtual void display(sf::RenderWindow &window) = 0;

        /**
         * @brief update, update the component
         */
        virtual void update() = 0;

        /**
         * @brief handleEvent, handle the event
         */
        virtual void handleEvent(const sf::Event &event, sf::RenderWindow &window, IComponent *parentComponent) = 0;

        /**
         * @brief pause, pause the component
         */
        virtual void pause() = 0;

        /**
         * @brief resume, resume the component
         */
        virtual void resume() = 0;

        /**
         * @brief addSubComponent, add a sub component
         */
        virtual void addSubComponent(std::shared_ptr<IComponent> component) = 0;

        /**
         * @brief getSubComponents, get all the sub components
         */
        virtual std::vector<std::shared_ptr<IComponent>> getSubComponents() = 0;

        /**
         * @brief setAttribute, set the attribute
         */
        virtual void setAttribute(const std::string &attribute) = 0;

        /**
         * @brief getAttribute, get the attribute
         */
        virtual std::string getAttribute() const = 0;

        /**
         * @brief setPosition, set the position
         */
        virtual void setPosition(const sf::Vector2f &position) = 0;

        /**
         * @brief getPosition, get the position
         */
        virtual sf::Vector2f getPosition() const = 0;

        /**
         * @brief setSize, set the size
         */
        virtual void setSize(const sf::Vector2f &size) = 0;

        /**
         * @brief getSize, get the size
         */
        virtual sf::Vector2f getSize() const = 0;

        /**
         * @brief setHeight, set the height
         */
        virtual void setHeight(float height) = 0;

        /**
         * @brief getHeight, get the height
         */
        virtual float getHeight() const = 0;

        /**
         * @brief setWidth, set the width
         */
        virtual void setWidth(float width) = 0;

        /**
         * @brief getWidth, get the width
         */
        virtual float getWidth() const = 0;

        /**
         * @brief getSubComponentByAttribute, get the sub component by attribute
         */
        virtual std::shared_ptr<IComponent> getSubComponentByAttribute(const std::string &attribute) = 0;

    protected:
        /**
         * @brief _subComponents, the sub components
         */
        std::vector<std::shared_ptr<IComponent>> _subComponents;

        /**
         * @brief _core, the core
         */
        Core *_core;

        /**
         * @brief _attribute, the attribute
         */
        std::string _attribute;

        /**
        * @brief _position, the position
        */
        sf::Vector2f _position{0, 0};

        /**
         * @brief _size, the size
         */
        sf::Vector2f _size{1, 1};

    /**
     * @brief height, the height
     */
        float _height = 1080;

    /**
     * @brief width, the width
     */
    float _width = 1920;
};
