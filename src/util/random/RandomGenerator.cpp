//
// Created by alber on 15/04/2019.
//

#include <iostream>
#include <time.h>
#include "RandomGenerator.h"

std::mt19937 RandomGenerator::mt(time(nullptr));

double RandomGenerator::getDouble(double start, double end) {
    std::uniform_real_distribution<double> dist(start, end);
    return dist(mt);
}

int RandomGenerator::getInt(int start, int end) {
    std::uniform_int_distribution<int> dist(start, end-1);
    return dist(mt);
}
