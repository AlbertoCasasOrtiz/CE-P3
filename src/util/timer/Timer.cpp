//
// Created by alber on 19/04/2019.
//

#include <chrono>
#include "Timer.h"

Timer::Timer() {
    this->start = 0;
    this->stop = 0;
}

void Timer::tic() {
    this->start = std::clock();
}

void Timer::tac() {
    this->stop = std::clock();
}

long Timer::getTime() {
    long diffticks = this->stop - this->start;
    long diffs = diffticks;
    return diffs;
}
