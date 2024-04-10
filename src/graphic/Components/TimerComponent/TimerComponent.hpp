//
// Created by talleux on 4/10/24.
//

#pragma once

#include "../AComponent.hpp"

class TimerComponent : public AComponent
{
    public:
        /**
         * @brief TimerComponent, constructor of TimerComponent
         */
        explicit TimerComponent(Core *core) : AComponent(core) {}

        /**
         * @brief ~TimerComponent, destructor of TimerComponent
         */
        ~TimerComponent() override = default;

        /**
         * @brief update, update the component
         */
        void update() override;

        /**
         * @brief start, start the timer
         */
        void start();

        /**
         * @brief stop, stop the timer
         */
        void stop();

        /**
         * @brief setTargetTime, set the target time
         * @param targetTime
         */
        void setTargetTime(const timeval &targetTime);

        /**
         * @brief getElapsedTime, get the elapsed time
         * @return the elapsed time
         */
        timeval getElapsedTime();

        /**
         * @brief isFinished, check if the timer is finished
         * @return true if the timer is finished, false otherwise
         */
        bool isFinished();

        /**
         * @brief getTargetTime, get the target time
         */
        timeval getTargetTime() const;

    private:
        /**
         * @brief _targetTime, the target time
         */
        timeval _targetTime{};

        /**
         * @brief _currentTime, the current time
         */
        timeval _currentTime{};

        /**
         * @brief _timeDiff, the time difference
         */
        timeval _timeDiff{};

        /**
         * @brief _startTime, the start time
         */
        timeval _startTime{};


};
