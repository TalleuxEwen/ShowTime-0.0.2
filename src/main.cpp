//
// Created by talleux on 4/7/24.
//

#include <iostream>
#include <pulse/simple.h>
#include <SFML/Audio.hpp>

#include "core/Core.hpp"
#include "audio/AudioEngine/Inputs/Inputs.hpp"
#include "audio/AudioEngine/Outputs/Outputs.hpp"
#include "audio/AudioEngine/AudioEngine.hpp"

int main() {
    std::shared_ptr<BuffersPool> buffersPool = std::make_shared<BuffersPool>();

    AudioEngine audioEngine(buffersPool);

    Core core(std::make_shared<AudioEngine>(audioEngine));

    while (!core.getWindows().empty())
    {
        core.run();
    }
}
