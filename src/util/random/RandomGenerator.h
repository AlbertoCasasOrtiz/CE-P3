//
// Created by alber on 15/04/2019.
//

#ifndef CE_ACTIVIDAD_3_RANDOMGENERATOR_H
#include <random>
#include <sstream>
#define CE_ACTIVIDAD_3_RANDOMGENERATOR_H



class RandomGenerator {
private:
    static std::random_device rd;
public:
    double static getDouble(double start, double end);
    int static getInt(int start, int end);
};


#endif //CE_ACTIVIDAD_3_RANDOMGENERATOR_H
