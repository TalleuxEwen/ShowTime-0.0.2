//
// Created by talleux on 4/12/24.
//

#include <iostream>
#include <utility>
#include <thread>
#include <cstring>
#include "Outputs.hpp"
#include "../BuffersPool.hpp"

Outputs::Outputs(std::string deviceName, int numDevice, std::shared_ptr<BuffersPool> buffersPool, int numChannels, int sampleRate, int bufferSize)
    : _deviceName(std::move(deviceName)), _numDevice(numDevice), _bufferSize(bufferSize), _buffersPool(std::move(buffersPool))
{
    setSampleSpec(sampleRate, numChannels);

    std::string nameToShowOutput = _deviceName + "_Virtual_Output";

    _simple = pa_simple_new(nullptr, (nameToShowOutput + "_" + std::to_string(_numDevice)).c_str(), PA_STREAM_PLAYBACK, nullptr, (nameToShowOutput + "_" + std::to_string(_numDevice)).c_str(), &_sampleSpec, nullptr, nullptr, nullptr);
    if (!_simple) {
        _isReady = false;
        std::cerr << "Failed to initialize virtual output " << _numDevice << std::endl;
    } else
        _isReady = true;

}

Outputs::~Outputs()
{
    if (_isReady)
        pa_simple_free(_simple);
}

void Outputs::setSampleSpec(int sampleRate, int numChannels)
{
    _sampleSpec.format = PA_SAMPLE_FLOAT32LE;
    _sampleSpec.rate = sampleRate;
    _sampleSpec.channels = numChannels;
}

void Outputs::run(std::shared_ptr<Buffer> buffer)
{
    while (_isReady) {

        auto *tmpBuffer = (float *)malloc(_bufferSize * sizeof(float));

        std::memset(tmpBuffer, 0, _bufferSize * sizeof(float));

        for (auto &input : _inputsToBroadcast) {
            while (!_buffersPool->getInputBuffer(input, _bufferSize)->isUpdated()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            for (int i = 0; i < _bufferSize; i++) {
                tmpBuffer[i] += _buffersPool->getInputBuffer(input, _bufferSize)->getBuffer()[i];
            }
            _buffersPool->getInputBuffer(input, _bufferSize)->setUpdated(false);
            _buffersPool->getInputBuffer(input, _bufferSize)->getMutex()->unlock();
        }

        for (int i = 0; i < _bufferSize; i++)
            buffer->getBuffer()[i] = tmpBuffer[i];

        //buffer->getMutex()->lock();

        int error;

        for (int i = 0; i < _bufferSize; i++)
            buffer->getBuffer()[i] *= _soundLevel;

        if (pa_simple_write(_simple, buffer->getBuffer(), _bufferSize * sizeof(float), &error) < 0) {
            std::cerr << "Failed to write to virtual output " << _numDevice << std::endl;
            buffer->getMutex()->unlock();
            return;
        }

        /*std::cout << "_soundLevel : " << _soundLevel << std::endl;
        std::cout << "out buffer :";
        for (int i = 0; i < _bufferSize; i++)
            std::cout << buffer[i] << " ";
        std::cout << std::endl;*/

        //_buffersPool->setOutputReady(std::to_string(_numDevice), false);

        buffer->setUpdated(false);

        //buffer->getMutex()->unlock();
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}
