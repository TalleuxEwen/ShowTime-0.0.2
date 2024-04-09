//
// Created by talleux on 4/8/24.
//

#include "Core.hpp"

Core::Core()
{
    _windows.push_back(std::make_shared<Window>(this, "ShowTime 0.0.2", sf::Vector2u(1920, 1080)));

}

void Core::run()
{
    /*for (auto &window : _windows)
    {
        if (window->isOpen())
        {
            window->clear();
            window->handleEvent();
            if (!window->isOpen()) {
                continue;
            }
            window->display();
        } else {
            removeWindow(window->getWindowId());
        }
    }*/

    if (_windows[0]->isOpen())
    {
        _windows[0]->clear();
        _windows[0]->handleEvent();
        if (_windows[0]->isOpen()) {
            _windows[0]->drawScene();
            _windows[0]->display();
        }
    }
    else
        removeWindow(_windows[0]->getWindowId());
}

void Core::addWindow(const std::string& windowName, sf::Vector2u windowSize)
{
    _windows.push_back(std::make_shared<Window>(this, windowName, windowSize));
}

std::shared_ptr<Window> Core::getWindow(unsigned int windowId)
{
    for (auto &window : _windows)
    {
        if (window->getWindowId() == windowId)
            return window;
    }
    return nullptr;
}

void Core::removeWindow(unsigned int windowId)
{
    for (auto it = _windows.begin(); it != _windows.end(); it++)
    {
        if ((*it)->getWindowId() == windowId)
        {
            _windows.erase(it);
            return;
        }
    }
}

std::vector<std::shared_ptr<Window>> Core::getWindows() const
{
    return _windows;
}
