//
// Created by talleux on 4/9/24.
//

#pragma once

#include "IScene.hpp"

class AScene : public IScene {
    public:
        /**
         * @brief AScene, constructor of AScene
         */
        explicit AScene(Core *core) : IScene(core) {
        }

        /**
         * @brief ~AScene, destructor of AScene
         */
        ~AScene() override = default;

        /**
         * @brief addComponent, add a component
         */
        void addComponent(std::shared_ptr<IComponent> component) override;

        /**
         * @brief getComponents, get all the components
         */
        std::vector<std::shared_ptr<IComponent>> getComponents() override;

        /**
         * @brief display, display the scene
         */
        void display(sf::RenderWindow &window) override;

        /**
         * @brief handleEvent, handle the event
         */
        void handleEvent(const sf::Event &event, sf::RenderWindow &window) override;

        /**
         * @brief update, update the scene
         */
        void update() override;

        /**
         * @brief pauseScene, pause the scene
         */
        void pauseScene() override;

        /**
         * @brief resumeScene, resume the scene
         */
        void resumeScene() override;

};