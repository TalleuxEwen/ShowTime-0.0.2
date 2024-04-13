//
// Created by talleux on 4/13/24.
//

#pragma once

#include <mutex>
#include <vector>
#include <iostream>

class Buffer
{
    public:
        /**
         * @brief Construct a new Buffer object
         *
         */
        Buffer(int size);

        /**
         * @brief Destroy the Buffer object
         *
         */
        ~Buffer();

        /**
         * @brief getBuffer, get the buffer
         * @return the buffer
         */
        float *getBuffer() { return _buffer; }

        /**
         * @brief getSize, get the size
         * @return the size
         */
        int getSize() { return _size; }

        /**
         * @brief getMutex, get the mutex
         * @return the mutex
         */
        std::mutex *getMutex() { return &_mutex; }

        /**
         * @brief setBuffer, set the buffer
         * @param buffer
         */
        void setBuffer(float *buffer);

        /**
         * @brief setUpdated, set the updated
         * @param updated
         */
        void setUpdated(bool updated) { _updated = updated; }

        /**
         * @brief isUpdated, check if the buffer is updated
         * @return true if the buffer is updated, false otherwise
         */
        bool isUpdated() { return _updated; }

        /**
         * @brief addToBeVisitedBy, add to be visited by
         * @param name
         */
        void addToBeVisitedBy(const std::string &name) { _toBeVisitedBy.push_back(name); }

        /**
         * @brief addVisitedBy, add visited by
         * @param name
         */

        void addVisitedBy(const std::string &name);

    private:
        /**
         * @brief _buffer, the buffer
         */
        float *_buffer;

        /**
         * @brief _size, the size
         */
        int _size;

        /**
         * @brief _mutex, the mutex
         */
        std::mutex _mutex;

        /**
         * @brief _updated, the updated
         */
        bool _updated;

        /**
         * @brief _visitedBy, the visited by
         */
        std::vector<std::string> _visitedBy;

        /**
         * @brief _toBeVisitedBy, the to be visited by
         */
        std::vector<std::string> _toBeVisitedBy;

};
