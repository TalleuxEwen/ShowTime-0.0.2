//
// Created by talleux on 4/12/24.
//

#include <string>
#include "BuffersPool.hpp"

BuffersPool::BuffersPool()
{
}

BuffersPool::~BuffersPool()
{
}

void BuffersPool::addInputBuffer(const std::string& name, int bufferSize)
{
    _inputsBuffers[name] = std::make_shared<Buffer>(bufferSize);
}

void BuffersPool::addOutputBuffer(const std::string& name, int bufferSize)
{
    _outputsBuffers[name] = std::make_shared<Buffer>(bufferSize);
}

std::shared_ptr<Buffer> BuffersPool::getInputBuffer(const std::string& name, int bufferSize)
{
    if (_inputsBuffers[name] == nullptr)
        addInputBuffer(name, bufferSize);
    return _inputsBuffers[name];
}

std::shared_ptr<Buffer> BuffersPool::getOutputBuffer(const std::string& name, int bufferSize)
{
    if (_outputsBuffers[name] == nullptr)
        addOutputBuffer(name, bufferSize);
    return _outputsBuffers[name];
}