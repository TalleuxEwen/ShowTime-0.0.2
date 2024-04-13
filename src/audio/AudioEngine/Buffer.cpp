//
// Created by talleux on 4/13/24.
//

#include <algorithm>
#include "Buffer.hpp"

Buffer::Buffer(int size)
    : _size(size)
{
    _buffer = new float[size];
}

Buffer::~Buffer()
{
    delete[] _buffer;
}

void Buffer::setBuffer(float *buffer)
{
    for (int i = 0; i < _size; i++)
        _buffer[i] += buffer[i];
}

void Buffer::addVisitedBy(const std::string &name) {
    if (!(std::find(_visitedBy.begin(), _visitedBy.end(), name) != _visitedBy.end()))
        _visitedBy.push_back(name);

    // Check if all the outputs have visited the buffer
    if (_visitedBy.size() == _toBeVisitedBy.size()) {
        setUpdated(true);
        _visitedBy.clear();
    }
}
