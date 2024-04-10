//
// Created by talleux on 4/10/24.
//

#pragma once

#include "../AScene.hpp"

class MainScene : public AScene
{
    public:
        /**
         * @brief MainScene, constructor of MainScene
         */
        explicit MainScene(Core *core);

        /**
         * @brief ~MainScene, destructor of MainScene
         */
        ~MainScene() override = default;

        /**
         * @brief update, update the scene
         */
        void update() override;

        /**
         * @brief handleEvent, handle the event
         * @param event
         * @param window
         */
        void handleEvent(const sf::Event &event, sf::RenderWindow &window) override;

        /**
         * @brief initScene, init the scene
         */
        void initScene();

};
