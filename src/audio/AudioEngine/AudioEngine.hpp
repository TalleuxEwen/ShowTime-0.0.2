//
// Created by talleux on 4/10/24.
//

#pragma once

#include <vector>
#include <memory>
#include <thread>
#include <map>
#include <mutex>
#include "Outputs/Outputs.hpp"
#include "BuffersPool.hpp"
#include "Inputs/Inputs.hpp"

class AudioEngine
{
    public:
        /**
         * @brief Construct a new Audio Engine object
         *
         */
        explicit AudioEngine(std::shared_ptr<BuffersPool> buffersPool);

        /**
         * @brief Destroy the Audio Engine object
         *
         */
        ~AudioEngine();

        /**
         * @brief getInputs, get the inputs
         * @return std::map<std::string, std::shared_ptr<Inputs>>
         */
        std::map<std::string, std::shared_ptr<Inputs>> getInputs();

        /**
         * @brief getOutputs, get the outputs
         * @return std::map<std::string, std::shared_ptr<Outputs>>
         */
        std::map<std::string, std::shared_ptr<Outputs>> getOutputs();

        /**
         * @brief getBuffersPool, get the buffers pool
         * @return std::shared_ptr<BuffersPool>
         */
        std::shared_ptr<BuffersPool> getBuffersPool();

        /**
         * @brief getLevelFromBuffer, get the level from buffer
         * @param buffer, the buffer
         * @param size, the size
         * @param nbChannels, the number of channels
         * @return float*, the level
         */
        static float *getLevelFromBuffer(const float *buffer, int size, int nbChannels);

    private:
        /**
         * @brief _inputs, the inputs
         */
        std::map<std::string, std::shared_ptr<Inputs>> _inputs;

        /**
         * @brief _outputs, the outputs
         */
        std::map<std::string, std::shared_ptr<Outputs>> _outputs;

        /**
         * @brief _inputsThreadPool, the inputs thread pool
         */
        std::map<std::string, std::tuple<std::shared_ptr<std::thread>>> _inputsThreadPool;

        /**
         * @brief _outputsThreadPool, the outputs thread pool
         */
        std::map<std::string, std::tuple<std::shared_ptr<std::thread>>> _outputsThreadPool;

        /**
         * @brief _buffersPool, the buffers pool
         */
         std::shared_ptr<BuffersPool> _buffersPool;




};
