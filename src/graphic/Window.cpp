//
// Created by talleux on 4/8/24.
//

#include "Window.hpp"
#include "../core/Core.hpp"
#include "../graphic/Scenes/LoadScene/LoadScene.hpp"

#include <utility>
#include <iostream>

Window::Window(Core *core, std::string windowName, sf::Vector2u windowSize)
{
    _core = core;

    _windowId = 0;
    _windowName = std::move(windowName);
    _windowSize = windowSize;
    _windowPosition = sf::Vector2i(0, 0);
    _windowMouseStyle = sf::Cursor::Arrow;
    _windowFramerateLimit = 60;
    _windowVerticalSyncEnabled = false;
    _windowMouseCursorVisible = true;

    _renderWindow.create(sf::VideoMode(_windowSize.x, _windowSize.y), _windowName);

    setWindowFramerateLimit(_windowFramerateLimit);
    setWindowVerticalSyncEnabled(_windowVerticalSyncEnabled);
    setWindowMouseCursorVisible(_windowMouseCursorVisible);
    //setWindowMouseStyle(_windowMouseStyle);
    setWindowPosition(_windowPosition);
    setWindowSize(_windowSize);

    sf::Image icon;
    if (!icon.loadFromFile("assets/icon.png")) {
        std::cerr << "Error: could not load icon.png" << std::endl;
    } else {
        _renderWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    _scenePool["Loading"] = std::make_shared<LoadScene>(_core);

    _currentScene = getSceneByName("Loading");
}

bool Window::isOpen() const
{
    return _renderWindow.isOpen();
}

void Window::close()
{
    _renderWindow.close();
    _core->removeWindow(_windowId);
}

void Window::clear()
{
    _renderWindow.clear(sf::Color::Black);
}

void Window::display()
{
    _renderWindow.display();
}

bool Window::pollEvent()
{
    return _renderWindow.pollEvent(_windowEvent);
}

void Window::handleEvent()
{
    while (pollEvent())
    {
        if (_windowEvent.type == sf::Event::Closed)
            close();

        _currentScene->handleEvent(_windowEvent, _renderWindow);
    }
}

void Window::drawScene()
{
    _currentScene->display(_renderWindow);
}

void Window::update()
{
    _currentScene->update();
}

void Window::changeScene(std::string sceneName)
{
    auto scene = getSceneByName(sceneName);
    if (scene == nullptr)
    {
        std::cerr << "Error: could not find scene " << sceneName << std::endl;
        return;
    }
    _currentScene = getSceneByName(std::move(sceneName));
}

//getters

unsigned int Window::getWindowId() const
{
    return _windowId;
}

std::shared_ptr<IScene> Window::getCurrentScene() const
{
    return _currentScene;
}

std::map<std::string, std::shared_ptr<IScene>> Window::getScenePool() const
{
    return _scenePool;
}

sf::RenderWindow &Window::getRenderWindow()
{
    return _renderWindow;
}

std::shared_ptr<IScene> Window::getSceneByName(std::string name)
{
    return _scenePool[name];
}

sf::Vector2u Window::getWindowSize() const
{
    return _windowSize;
}

sf::Vector2i Window::getWindowPosition() const
{
    return _windowPosition;
}

sf::Cursor::Type Window::getWindowMouseStyle() const
{
    return _windowMouseStyle;
}

std::string Window::getWindowName() const
{
    return _windowName;
}

sf::Event Window::getWindowEvent() const
{
    return _windowEvent;
}

unsigned int Window::getWindowFramerateLimit() const
{
    return _windowFramerateLimit;
}

bool Window::getWindowVerticalSyncEnabled() const
{
    return _windowVerticalSyncEnabled;
}

bool Window::getWindowMouseCursorVisible() const
{
    return _windowMouseCursorVisible;
}

//setters

void Window::setWindowId(unsigned int windowId)
{
    _windowId = windowId;
}

void Window::setWindowSize(const sf::Vector2u &windowSize)
{
    _windowSize = windowSize;
}

void Window::setWindowPosition(const sf::Vector2i &windowPosition)
{
    _windowPosition = windowPosition;
    _renderWindow.setPosition(_windowPosition);
}

void Window::setWindowMouseStyle(sf::Cursor::Type windowMouseStyle)
{
    _renderWindow.setMouseCursorVisible(windowMouseStyle);
    _windowMouseStyle = windowMouseStyle;
}

void Window::setWindowName(const std::string &windowName)
{
    _windowName = windowName;
    _renderWindow.setTitle(_windowName);
}

void Window::setWindowEvent(const sf::Event &windowEvent)
{
    _windowEvent = windowEvent;
}

void Window::setWindowFramerateLimit(unsigned int windowFramerateLimit)
{
    _renderWindow.setFramerateLimit(windowFramerateLimit);
    _windowFramerateLimit = windowFramerateLimit;
}

void Window::setWindowVerticalSyncEnabled(bool windowVerticalSyncEnabled)
{
    _renderWindow.setVerticalSyncEnabled(windowVerticalSyncEnabled);
    _windowVerticalSyncEnabled = windowVerticalSyncEnabled;
}

void Window::setWindowMouseCursorVisible(bool windowMouseCursorVisible)
{
    _renderWindow.setMouseCursorVisible(windowMouseCursorVisible);
    _windowMouseCursorVisible = windowMouseCursorVisible;
}
