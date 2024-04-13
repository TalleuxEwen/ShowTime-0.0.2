//
// Created by talleux on 4/10/24.
//

#pragma once

#include <pulse/simple.h>
#include <string>
#include <iostream>
#include <mutex>
#include <memory>
#include "../BuffersPool.hpp"

class Inputs
{
    public:
        /**
         * @brief Construct a new Inputs object
         *
         */
        Inputs(std::string deviceName, int numDevice, std::shared_ptr<BuffersPool> buffersPool, int numChannels = 2, int sampleRate = 44100, int bufferSize = 1024);
/**
         * @brief Destroy the Inputs object
         *
         */
        ~Inputs();

        /**
         * @brief setSampleSpec, set the sample spec
         *
         * @param sampleRate
         * @param numChannels
         */
        void setSampleSpec(int sampleRate, int numChannels);

        /**
         * @brief isReady, check if the input is ready
         * @return true if the input is ready, false otherwise
         */
        bool isReady() const { return _isReady; }

        /**
         * @brief getSimple, get the pulse audio simple
         * @return the pulse audio simple
         */
        pa_simple *getSimple() { return _simple; }

        /**
         * @brief run, run the input
         */
        void run(std::shared_ptr<Buffer> buffer);

        /**
         * @brief stop, stop the input
         */
        void stop() { _isReady = false; }

        /**
         * @brief getSoundLevel, get the sound level
         * @return the sound level
         */
        float getSoundLevel() { return _soundLevel; }

        /**
         * @brief setSoundLevel, set the sound level
         * @param soundLevel, the sound level
         */
        void setSoundLevel(float soundLevel) { _soundLevel = soundLevel; }

        /**
         * @brief addExitOutput, add an exit output
         * @param output, the output
         */
        void addExitOutput(std::string output) { _exitOutputs.push_back(output); }

        /**
         * @brief deleteExitOutput, delete an exit output
         * @param output, the output
         */
        void deleteExitOutput(std::string output);

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
         * @brief _bufferSize, the buffer size
         */
        int _bufferSize;

        /**
         * @brief _isReady, the state of the input
         */
        bool _isReady = false;

        /**
         * @brief _simple, the pulse audio simple
         */
        pa_simple *_simple;

        /**
         * @brief _id, the id
         */
        int _id;

        /**
         * @brief _soundLevel, the sound level
         */
        float _soundLevel = 0;

        /**
         * @brief _buffersPool, the buffers pool
         */
        std::shared_ptr<BuffersPool> _buffersPool;

        /**
         * @brief exitOutputs, exit the outputs
         */
        std::vector<std::string> _exitOutputs;

};
