//
// Created by talleux on 4/10/24.
//

#pragma once

#include "../AComponent.hpp"
#include "../SpriteComponent/SpriteComponent.hpp"

class VueMeterComponent : public AComponent
{
    public:
        /**
         * @brief VueMeterComponent, constructor of VueMeterComponent
         */
        explicit VueMeterComponent(Core *core);

        /**
         * @brief ~VueMeterComponent, destructor of VueMeterComponent
         */
        ~VueMeterComponent() override = default;

        /**
         * @brief init, init the vue meter
         */
        void init();

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
         * @brief display, display the vue meter
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
         * @brief setVolumeValues, set the volume
         * @param volume
         */
        void setVolumeValues(const float *volume, int size);

        /**
         * @brief update, update the component
         */
        void update() override;

    private:
        float _leftVolumeValue = 10;
        float _rightVolumeValue = 50;

};
