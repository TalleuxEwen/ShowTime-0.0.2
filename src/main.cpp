//
// Created by talleux on 4/7/24.
//

#include <iostream>
#include <pulse/simple.h>
#include <SFML/Audio.hpp>

#include "core/Core.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Core core;

    while (!core.getWindows().empty())
    {
        core.run();
    }
}
