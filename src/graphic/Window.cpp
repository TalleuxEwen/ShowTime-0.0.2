//
// Created by talleux on 4/8/24.
//

#include "Window.hpp"
#include "../core/Core.hpp"

#include <utility>

Window::Window(Core *core, std::string windowName, sf::Vector2u windowSize)
{
    _windowId = 0;
    _windowName = std::move(windowName);
    _windowSize = windowSize;
    _windowPosition = sf::Vector2i(0, 0);
    _windowMouseStyle = sf::Cursor::Arrow;
    _windowFramerateLimit = 60;
    _windowVerticalSyncEnabled = false;
    _windowMouseCursorVisible = true;

    _renderWindow = new sf::RenderWindow(sf::VideoMode(_windowSize.x, _windowSize.y), _windowName);

    setWindowFramerateLimit(_windowFramerateLimit);
    setWindowVerticalSyncEnabled(_windowVerticalSyncEnabled);
    setWindowMouseCursorVisible(_windowMouseCursorVisible);
    //setWindowMouseStyle(_windowMouseStyle);
    setWindowPosition(_windowPosition);
    setWindowSize(_windowSize);

    _core = core;
}

bool Window::isOpen() const
{
    return _renderWindow->isOpen();
}

void Window::close()
{
    _renderWindow->close();
    _core->removeWindow(_windowId);
}

void Window::clear()
{
    _renderWindow->clear();
}

void Window::display()
{
    _renderWindow->display();
}

bool Window::pollEvent()
{
    return _renderWindow->pollEvent(_windowEvent);
}

void Window::handleEvent()
{
    while (pollEvent())
    {
        if (_windowEvent.type == sf::Event::Closed)
            close();

        if (_windowEvent.type == sf::Event::KeyPressed)
        {
            if (_windowEvent.key.code == sf::Keyboard::Space)
                _core->addWindow("Window", sf::Vector2u(800, 600));

        }
    }
}

void Window::drawComponents()
{
}

//getters

unsigned int Window::getWindowId() const
{
    return _windowId;
}

sf::RenderWindow *Window::getRenderWindow() const
{
    return _renderWindow;
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
    _renderWindow->setPosition(_windowPosition);
}

void Window::setWindowMouseStyle(sf::Cursor::Type windowMouseStyle)
{
    _renderWindow->setMouseCursorVisible(windowMouseStyle);
    _windowMouseStyle = windowMouseStyle;
}

void Window::setWindowName(const std::string &windowName)
{
    _windowName = windowName;
    _renderWindow->setTitle(_windowName);
}

void Window::setWindowEvent(const sf::Event &windowEvent)
{
    _windowEvent = windowEvent;
}

void Window::setWindowFramerateLimit(unsigned int windowFramerateLimit)
{
    _renderWindow->setFramerateLimit(windowFramerateLimit);
    _windowFramerateLimit = windowFramerateLimit;
}

void Window::setWindowVerticalSyncEnabled(bool windowVerticalSyncEnabled)
{
    _renderWindow->setVerticalSyncEnabled(windowVerticalSyncEnabled);
    _windowVerticalSyncEnabled = windowVerticalSyncEnabled;
}

void Window::setWindowMouseCursorVisible(bool windowMouseCursorVisible)
{
    _renderWindow->setMouseCursorVisible(windowMouseCursorVisible);
    _windowMouseCursorVisible = windowMouseCursorVisible;
}
