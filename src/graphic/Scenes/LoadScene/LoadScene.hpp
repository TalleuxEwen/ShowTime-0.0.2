//
// Created by talleux on 4/9/24.
//

#pragma once

#include "../AScene.hpp"

class LoadScene : public AScene
{
    public:
        /**
         * @brief LoadScene, constructor of LoadScene
         */
        explicit LoadScene(Core *core);

        /**
         * @brief ~LoadScene, destructor of LoadScene
         */
        ~LoadScene() override = default;

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
