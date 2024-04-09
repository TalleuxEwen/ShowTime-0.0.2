//
// Created by talleux on 4/9/24.
//

#pragma once

#include "IComponent.hpp"

class AComponent : public IComponent
{
    public:
        /**
         * @brief AComponent, constructor of AComponent
         */
        explicit AComponent(Core *core) : IComponent(core) {}

        /**
         * @brief ~AComponent, destructor of AComponent
         */
        ~AComponent() override = default;

        /**
         * @brief display, display the component
         */
        void display(sf::RenderWindow &window) override;

        /**
         * @brief handleEvent, handle the event
         */
        void handleEvent(const sf::Event &event, sf::RenderWindow &window) override;

        /**
         * @brief update, update the component
         */
        void update() override;

        /**
         * @brief pause, pause the component
         */
        void pause() override;

        /**
         * @brief resume, resume the component
         */
        void resume() override;

        /**
         * @brief addSubComponent, add a sub component
         */
         void addSubComponent(std::shared_ptr<IComponent> component) override;

         /**
          * @brief getSubComponents, get all the sub components
          */
         std::vector<std::shared_ptr<IComponent>> getSubComponents() override;

};
