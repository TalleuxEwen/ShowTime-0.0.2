//
// Created by talleux on 4/12/24.
//

#pragma once

#include <pulse/simple.h>
#include <string>
#include <mutex>
#include <memory>
#include "../BuffersPool.hpp"

class Outputs
{
    public:
        /**
         * @brief Construct a new Outputs object
         *
         */
        Outputs(std::string  deviceName, int numDevice, std::shared_ptr<BuffersPool> buffersPool, int numChannels = 2, int sampleRate = 44100, int bufferSize = 1024);

        /**
         * @brief Destroy the Outputs object
         *
         */
        ~Outputs();

        /**
         * @brief setSampleSpec, set the sample spec
         *
         * @param sampleRate
         * @param numChannels
         */
        void setSampleSpec(int sampleRate, int numChannels);

        /**
         * @brief isReady, check if the output is ready
         * @return true if the output is ready, false otherwise
         */
        bool isReady() const { return _isReady; }

        /**
         * @brief getSimple, get the pulse audio simple
         * @return the pulse audio simple
         */
        pa_simple *getSimple() { return _simple; }

        /**
         * @brief run, run the output
         * @param buffer, the buffer
         */
        void run(std::shared_ptr<Buffer> buffer);

        /**
         * @brief stop, stop the output
         */
        void stop() { _isReady = false; }

        /**
         * @brief setSoundLevel, set the sound level
         * @param soundLevel, the sound level
         */
        void setSoundLevel(float soundLevel) { _soundLevel = soundLevel; }

        /**
         * @brief getSoundLevel, get the sound level
         * @return the sound level
         */
        float getSoundLevel() { return _soundLevel; }

        /**
         * @brief addInputToBroadcast, add an input to broadcast
         * @param input, the input
         */
        void addInputToBroadcast(const std::string &input) { _inputsToBroadcast.push_back(input); }

    private:
        /**
         * @brief _sampleSpec, the sample spec
         */
        pa_sample_spec _sampleSpec{};

        /**
         * @brief _deviceName, the device name
         */
        std::string _deviceName;

        /**
         * @brief _numDevice, the number of device
         */
        int _numDevice;

        /**
         * @brief _simple, the pulse audio simple
         */
        pa_simple *_simple;

        /**
         * @brief _bufferSize, the buffer size
         */
        int _bufferSize;

        /**
         * @brief _isReady, the state of the output
         */
        bool _isReady = false;

        /**
         * @brief _soundLevel, the sound level
         */
        float _soundLevel = 0;

        /**
         * @brief _buffersPool, the buffers pool
         */
        std::shared_ptr<BuffersPool> _buffersPool;

        /**
         * @brief _inputsToBroadcast, the inputs to broadcast
         */
        std::vector<std::string> _inputsToBroadcast;


};
