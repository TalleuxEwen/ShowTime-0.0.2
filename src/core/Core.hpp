//
// Created by talleux on 4/8/24.
//

#pragma once

#include <memory>
#include <vector>
#include "../graphic/Window.hpp"

class Core
{
    public:

        /**
         * @brief Core, constructor of Core
         */
        Core();

        /**
         * @brief ~Core, destructor of Core
         */
        ~Core() = default;

    private:

            /**
            * @brief _socket, windows pool
            */
            std::vector<std::shared_ptr<Window>> _windows;
};
