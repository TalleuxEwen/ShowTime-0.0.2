//
// Created by talleux on 4/10/24.
//

#pragma once

#include <pulse/simple.h>
#include <string>

class Inputs
{
    public:
        /**
         * @brief Construct a new Inputs object
         *
         */
        Inputs(std::string deviceName, int numDevice, int numChannels = 2, int sampleRate = 44100, int bufferSize = 1024);

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

};
