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
        void handleEvent(const sf::Event &event, sf::RenderWindow &window, IComponent *parentComponent) override;

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

         /**
          * @brief setAttribute, set the attribute
          */
         void setAttribute(const std::string &attribute) override;

         /**
          * @brief getAttribute, get the attribute
          */
         std::string getAttribute() const override;

         /**
          * @brief setPosition, set the position
          */
         void setPosition(const sf::Vector2f &position) override;

         /**
          * @brief getPosition, get the position
          */
         sf::Vector2f getPosition() const override;

         /**
          * @brief setSize, set the size
          */
         void setSize(const sf::Vector2f &size) override;

         /**
          * @brief getSize, get the size
          */
         sf::Vector2f getSize() const override;

         /**
          * @brief setHeight, set the height
          */
         void setHeight(float height) override;

         /**
          * @brief getHeight, get the height
          */
         float getHeight() const override;

         /**
          * @brief setWidth, set the width
          */
         void setWidth(float width) override;

         /**
          * @brief getWidth, get the width
          */
         float getWidth() const override;

         /**
          * @brief getSubComponentByAttribute, get a sub component by its attribute
          */
         std::shared_ptr<IComponent> getSubComponentByAttribute(const std::string &attribute) override;

};
