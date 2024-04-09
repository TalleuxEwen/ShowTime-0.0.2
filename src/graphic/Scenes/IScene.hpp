//
// Created by talleux on 4/9/24.
//

#pragma once

#include <memory>
#include "../../core/Core.hpp"
#include "../Components/SpriteComponent/SpriteComponent.hpp"

class IScene
{
    public:
        /**
         * @brief IScene, constructor of IScene
         */
        explicit IScene(Core *core) : _core(core) {}

        /**
         * @brief ~IScene, destructor of IScene
         */
        virtual ~IScene() = default;

        /**
         * @brief addComponent, add a component
         */
        virtual void addComponent(std::shared_ptr<IComponent> component) = 0;

        /**
         * @brief getComponents, get all the components
         */
        virtual std::vector<std::shared_ptr<IComponent>> getComponents() = 0;

        /**
         * @brief display, display the scene
         */
        virtual void display(sf::RenderWindow &window) = 0;

        /**
         * @brief update, update the scene
         */
        virtual void update() = 0;

        /**
         * @brief handleEvent, handle the event
         */
        virtual void handleEvent(const sf::Event &event, sf::RenderWindow &window) = 0;

        /**
         * @brief pauseScene, pause the scene
         */
        virtual void pauseScene() = 0;

        /**
         * @brief resumeScene, resume the scene
         */
        virtual void resumeScene() = 0;

    private:

        /**
         * @brief _isPaused, is paused
         */
        bool _isPaused{};

    protected:
        /**
         * @brief _components, components
         */
        std::vector<std::shared_ptr<IComponent>> _components{};

        /**
         * @brief _core, core
         */
        Core *_core;
};
