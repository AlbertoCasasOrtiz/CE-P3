//
// Created by alber on 19/04/2019.
//

#include <chrono>
#include <iostream>
#include "Timer.h"
#include <chrono>

Timer::Timer() {
    this->start;
    this->stop;
}

void Timer::tic() {
    this->start = clock();
}

void Timer::tac() {
    this->stop = clock();
}

double Timer::getTime() {
    auto time = this->stop - this->start;
    std::cout << time*1.0/CLOCKS_PER_SEC << std::endl;
    return (time * 1.0/ CLOCKS_PER_SEC);
}
