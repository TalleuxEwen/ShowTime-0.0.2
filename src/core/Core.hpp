//
// Created by talleux on 4/8/24.
//

#pragma once

#include <memory>
#include <vector>
#include "../graphic/Window.hpp"
#include "../audio/AudioEngine/AudioEngine.hpp"

class Core
{
    public:

        /**
         * @brief Core, constructor of Core
         */
        explicit Core(std::shared_ptr<AudioEngine> audioEngine);

        /**
         * @brief ~Core, destructor of Core
         */
        ~Core() = default;

        /**
         * @brief run, run the core
         */
        void run();

        /**
         * @brief addWindow, add a window
         *
         * @param windowName
         * @param windowSize
         */
        void addWindow(const std::string& windowName, sf::Vector2u windowSize);

        /**
         * @brief getWindow, get the window
         *
         * @param windowId
         * @return std::shared_ptr<Window>
         */
        std::shared_ptr<Window> getWindow(unsigned int windowId);

        /**
         * @brief removeWindow, remove the window
         *
         * @param windowId
         */
        void removeWindow(unsigned int windowId);

        /**
         * @brief getWindows, get the windows
         *
         * @return std::vector<std::shared_ptr<Window>>
         */
        std::vector<std::shared_ptr<Window>> getWindows() const;

        /**
         * @brief getAudioEngine, get the audio engine
         *
         * @return std::shared_ptr<AudioEngine>
         */
        std::shared_ptr<AudioEngine> getAudioEngine() const;

    private:

            /**
            * @brief _socket, windows pool
            */
            std::vector<std::shared_ptr<Window>> _windows;

            /**
             * @brief _audioEngine, audio engine
             */
            std::shared_ptr<AudioEngine> _audioEngine;
};
