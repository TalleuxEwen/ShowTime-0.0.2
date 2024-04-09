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
        virtual void handleEvent(const sf::Event &event, sf::RenderWindow &window) = 0;

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

    private:
        /**
         * @brief _core, the core
         */
        Core *_core;

    protected:
        /**
         * @brief _subComponents, the sub components
         */
        std::vector<std::shared_ptr<IComponent>> _subComponents;
};
