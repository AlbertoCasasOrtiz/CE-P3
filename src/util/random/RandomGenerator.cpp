//
// Created by alber on 15/04/2019.
//

#include "RandomGenerator.h"

std::random_device RandomGenerator::rd;

double RandomGenerator::getDouble(double start, double end) {
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end-1);
    return dist(mt);
}

int RandomGenerator::getInt(int start, int end) {
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(start, end-1);
    return dist(mt);
}
