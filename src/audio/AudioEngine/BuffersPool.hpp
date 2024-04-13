//
// Created by talleux on 4/12/24.
//

#pragma once


#include <vector>
#include <memory>
#include <map>
#include "Buffer.hpp"

class BuffersPool
{
    public:
        /**
         * @brief Construct a new Buffers Pool object
         *
         */
        BuffersPool();

        /**
         * @brief Destroy the Buffers Pool object
         *
         */
        ~BuffersPool();

        /**
         * @brief addInputBuffer, add an input buffer
         *
         * @param name
         * @param buffer
         */
        void addInputBuffer(const std::string& name, int bufferSize);

        /**
         * @brief addOutputBuffer, add an output buffer
         *
         * @param name
         * @param buffer
         */
        void addOutputBuffer(const std::string& name, int bufferSize);

        /**
         * @brief getInputBuffer, get an input buffer
         *
         * @param name
         * @param bufferSize
         * @return float*
         */
        std::shared_ptr<Buffer> getInputBuffer(const std::string& name, int bufferSize);

        /**
         * @brief getOutputBuffer, get an output buffer
         *
         * @param name
         * @param bufferSize
         * @return float*
         */
        std::shared_ptr<Buffer> getOutputBuffer(const std::string& name, int bufferSize);

    private:
         /**
          * @brief _inputsBuffers, the inputs buffers
          */
         std::map<std::string, std::shared_ptr<Buffer>> _inputsBuffers;

         /**
          * @brief _outputsBuffers, the outputs buffers
          */
         std::map<std::string, std::shared_ptr<Buffer>> _outputsBuffers;
};
