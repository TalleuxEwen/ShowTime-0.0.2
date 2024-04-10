//
// Created by talleux on 4/10/24.
//

#include <sys/time.h>
#include "TimerComponent.hpp"

void TimerComponent::update()
{
    gettimeofday(&_currentTime, nullptr);
    timersub(&_currentTime, &_startTime, &_timeDiff);
}

void TimerComponent::start()
{
    gettimeofday(&_startTime, nullptr);
}

void TimerComponent::stop()
{
    _currentTime = {};
    _timeDiff = {};
    _startTime = {};
    _targetTime = {};
}

void TimerComponent::setTargetTime(const timeval &targetTime)
{
    _targetTime = targetTime;
}

timeval TimerComponent::getElapsedTime()
{
    return _timeDiff;
}

bool TimerComponent::isFinished()
{
    return timercmp(&_timeDiff, &_targetTime, >);
}

timeval TimerComponent::getTargetTime() const
{
    return _targetTime;
}
