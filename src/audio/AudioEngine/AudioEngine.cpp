//
// Created by talleux on 4/10/24.
//

#include "AudioEngine.hpp"

#include <utility>

AudioEngine::AudioEngine(std::shared_ptr<BuffersPool> buffersPool)
    : _buffersPool(std::move(buffersPool))
{
    _inputs["1"] = std::make_shared<Inputs>("ShowTime", 1, _buffersPool);
    _inputs["2"] = std::make_shared<Inputs>("ShowTime", 2, _buffersPool);
    _inputs["3"] = std::make_shared<Inputs>("ShowTime", 3, _buffersPool);

    _outputs["1"] = std::make_shared<Outputs>("ShowTime", 1, _buffersPool);
    _outputs["2"] = std::make_shared<Outputs>("ShowTime", 2, _buffersPool);
    _outputs["3"] = std::make_shared<Outputs>("ShowTime", 3, _buffersPool);

    //_inputs["1"]->addExitOutput("1");

    std::shared_ptr<std::thread> thread1 = std::make_shared<std::thread>([this](){
        _inputs["1"]->run(_buffersPool->getInputBuffer("1", 1024));
    });

    _inputsThreadPool["1"] = std::make_tuple(thread1);

    std::shared_ptr<std::thread> thread2 = std::make_shared<std::thread>([this](){
        _inputs["2"]->run(_buffersPool->getInputBuffer("2", 1024));
    });

    _inputsThreadPool["2"] = std::make_tuple(thread2);

    std::shared_ptr<std::thread> thread3 = std::make_shared<std::thread>([this](){
        _inputs["3"]->run(_buffersPool->getInputBuffer("3", 1024));
    });

    _inputsThreadPool["3"] = std::make_tuple(thread3);

    _outputs["1"]->addInputToBroadcast("1");
    _outputs["1"]->addInputToBroadcast("2");

    std::shared_ptr<std::thread> thread4 = std::make_shared<std::thread>([this](){
        _outputs["1"]->run(_buffersPool->getOutputBuffer("1", 1024));
    });

    _outputsThreadPool["1"] = std::make_tuple(thread4);

}

AudioEngine::~AudioEngine()
{
    for (auto &input : _inputs)
    {
        input.second->stop();
    }

    for (auto &thread : _inputsThreadPool)
    {
        if (std::get<0>(thread.second)->joinable())
            std::get<0>(thread.second)->join();
    }

    for (auto &output : _outputs)
    {
        output.second->stop();
    }

    for (auto &thread : _outputsThreadPool)
    {
        if (std::get<0>(thread.second)->joinable())
            std::get<0>(thread.second)->join();
    }
}

std::map<std::string, std::shared_ptr<Inputs>> AudioEngine::getInputs()
{
    return _inputs;
}

std::map<std::string, std::shared_ptr<Outputs>> AudioEngine::getOutputs()
{
    return _outputs;
}

std::shared_ptr<BuffersPool> AudioEngine::getBuffersPool()
{
    return _buffersPool;
}

float *AudioEngine::getLevelFromBuffer(const float *buffer, int size, int nbChannels)
{
    auto *level = new float[nbChannels];

    for (int i = 0; i < nbChannels; i++)
    {
        level[i] = 0;
    }

    for (int i = 0; i < size; i+=nbChannels)
    {
        for (int j = 0; j < nbChannels; j++)
        {
            level[j] = std::max(level[j], std::abs(buffer[i + j]));
        }
    }

    return level;
}
