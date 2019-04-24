//
// Created by Alberto Casas Ortiz.
//

#include <chrono>
#include <iostream>
#include "Timer.h"
#include <chrono>

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
