//
// Created by talleux on 4/7/24.
//

#include <iostream>
#include <pulse/simple.h>
#include <SFML/Audio.hpp>

#include "core/Core.hpp"
#include "audio/AudioEngine/Inputs/Inputs.hpp"

int main() {
    Core core;

    Inputs inputs("ShowTime", 1);
    Inputs inputs2("ShowTime", 2);
    Inputs inputs3("ShowTime", 3);

    while (!core.getWindows().empty())
    {
        core.run();
    }
}
