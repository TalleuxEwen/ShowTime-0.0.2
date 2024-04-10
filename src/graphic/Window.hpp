//
// Created by talleux on 4/8/24.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Core;

class IScene;

class Window
{
    public:

        /**
         * @brief Window, constructor of Window
         */
        Window(Core *core, std::string windowName, sf::Vector2u windowSize);

        /**
         * @brief ~Window, destructor of Window
         */
        ~Window() = default;

        /**
         * @brief isOpen, check if window is open
         * @return true if window is open, false otherwise
         */
        bool isOpen() const;

        /**
         * @brief close, close the window
         */
        void close();

        /**
         * @brief clear, clear the window
         */
        void clear();

        /**
         * @brief display, display the window
         */
        void display();

        /**
         * @brief pollEvent, poll the event
         * @return true if event is polled, false otherwise
         */
        bool pollEvent();

        /**
         * @brief handleEvent, handle the event
         */
        void handleEvent();

        /**
         * @brief drawComponents, draw components
         */
        void drawScene();

        /**
         * @brief update, update the window
         */
        void update();

        /**
         * @brief changeScene, change the scene
         */
        void changeScene(std::string sceneName);

        // Getters
        /**
         * @brief getWindowId, get the window id
         * @return the window id
         */
        unsigned int getWindowId() const;

        /**
         * @brief getCurrentScene, get the current scene
         * @return the current scene
         */
        std::shared_ptr<IScene> getCurrentScene() const;

        /**
         * @brief getScenePool, get the scene pool
         * @return the scene pool
         */
        std::map<std::string, std::shared_ptr<IScene>> getScenePool() const;

        /**
         * @brief getRenderWindow, get the render window
         * @return the render window
         */
        sf::RenderWindow &getRenderWindow();

        /**
         * @brief getCore, get the core
         * @return the core
         */
         std::shared_ptr<IScene> getSceneByName(std::string name);

        /**
         * @brief getWindowName, get the window name
         * @return the window name
         */
        std::string getWindowName() const;

        /**
         * @brief getWindowSize, get the window size
         * @return the window size
         */
        sf::Vector2u getWindowSize() const;

        /**
         * @brief getWindowPosition, get the window position
         * @return the window position
         */
        sf::Vector2i getWindowPosition() const;

        /**
         * @brief getWindowEvent, get the window event
         * @return the window event
         */
        sf::Event getWindowEvent() const;

        /**
         * @brief getWindowFramerateLimit, get the window framerate limit
         * @return the window framerate limit
         */
        unsigned int getWindowFramerateLimit() const;

        /**
         * @brief getWindowVerticalSyncEnabled, get the window vertical sync enabled
         * @return true if window vertical sync is enabled, false otherwise
         */
        bool getWindowVerticalSyncEnabled() const;

        /**
         * @brief getWindowMouseCursorVisible, get the window mouse cursor visible
         * @return true if window mouse cursor is visible, false otherwise
         */
        bool getWindowMouseCursorVisible() const;

        /**
         * @brief getWindowMouseStyle, get the window mouse style
         * @return the window mouse style
         */
        sf::Cursor::Type getWindowMouseStyle() const;

        // Setters
        /**
         * @brief setWindowId, set the window id
         * @param windowId
         */
        void setWindowId(unsigned int windowId);

        /**
         * @brief setCurrentScene, set the current scene
         * @param currentScene
         */
        //void setCurrentScene(std::shared_ptr<IScene> currentScene);

        /**
         * @brief setWindowName, set the window name
         * @param windowName
         */
        void setWindowName(const std::string &windowName);

        /**
         * @brief setWindowSize, set the window size
         * @param windowSize
         */
        void setWindowSize(const sf::Vector2u &windowSize);

        /**
         * @brief setWindowPosition, set the window position
         * @param windowPosition
         */
        void setWindowPosition(const sf::Vector2i &windowPosition);

        /**
         * @brief setWindowEvent, set the window event
         * @param windowEvent
         */
        void setWindowEvent(const sf::Event &windowEvent);

        /**
         * @brief setWindowFramerateLimit, set the window framerate limit
         * @param windowFramerateLimit
         */
        void setWindowFramerateLimit(unsigned int windowFramerateLimit);

        /**
         * @brief setWindowVerticalSyncEnabled, set the window vertical sync enabled
         * @param windowVerticalSyncEnabled
         */
        void setWindowVerticalSyncEnabled(bool windowVerticalSyncEnabled);

        /**
         * @brief setWindowMouseCursorVisible, set the window mouse cursor visible
         * @param windowMouseCursorVisible
         */
        void setWindowMouseCursorVisible(bool windowMouseCursorVisible);

        /**
         * @brief setWindowMouseStyle, set the window mouse style
         * @param windowMouseStyle
         */
        void setWindowMouseStyle(sf::Cursor::Type windowMouseStyle);


    protected:
            /**
             * @brief _windowId, window id
             */
            unsigned int _windowId;

            /**
             * @brief _currentScene, current scene
             */
            std::shared_ptr<IScene> _currentScene;

            /**
             * @brief _scenePool, scene pool
             */
            std::map<std::string, std::shared_ptr<IScene>> _scenePool;

            /**
             * @brief _renderWindow, render window
             */
            sf::RenderWindow _renderWindow;

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
             * @brief _windowEvent, window event
             */
            sf::Event _windowEvent{};

            /**
             * @brief _windowFramerateLimit, window framerate limit
             */
            unsigned int _windowFramerateLimit{};

            /**
             * @brief _windowVerticalSyncEnabled, window vertical sync enabled
             */
            bool _windowVerticalSyncEnabled{};

            /**
             * @brief _windowMouseCursorVisible, window mouse cursor visible
             */
            bool _windowMouseCursorVisible{};

            /**
             * @brief _windowMouseStyle, window mouse style
             */
            sf::Cursor::Type _windowMouseStyle;

            /**
             * @brief _core, core
             */
            Core *_core;

            /**
             * @brief _newScene, new scene
             */
             std::string _newScene;

};
