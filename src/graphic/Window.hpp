//
// Created by talleux on 4/8/24.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Window
{
    public:

        /**
         * @brief Window, constructor of Window
         */
        Window();

        /**
         * @brief ~Window, destructor of Window
         */
        ~Window() = default;

    private:
            /**
             * @brief _windowId, window id
             */
            unsigned int _windowId;

            /**
             * @brief _currentScene, current scene
             */
            //std::shared_ptr<IScene> _currentScene;

            /**
             * @brief _renderWindow, render window
             */
            sf::RenderWindow *_renderWindow;

            /**
             * @brief _windowName, window name
             */
            std::string _windowName;

            /**
             * @brief _windowSize, window size
             */
            sf::Vector2u _windowSize;

            /**
             * @brief _windowPosition, window position
             */
            sf::Vector2i _windowPosition;

            /**
             * @brief _windowStyle, window style
             */
            sf::Uint32 _windowStyle;

            /**
             * @brief _windowEvent, window event
             */
            sf::Event _windowEvent;

            /**
             * @brief _windowFramerateLimit, window framerate limit
             */
            unsigned int _windowFramerateLimit;

            /**
             * @brief _windowVerticalSyncEnabled, window vertical sync enabled
             */
            bool _windowVerticalSyncEnabled;

            /**
             * @brief _windowMouseCursorVisible, window mouse cursor visible
             */
            bool _windowMouseCursorVisible;

            /**
             * @brief _windowMouseStyle, window mouse style
             */
            sf::Cursor::Type _windowMouseStyle;


};
