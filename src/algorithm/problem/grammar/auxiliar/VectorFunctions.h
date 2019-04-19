//
// Created by alber on 18/04/2019.
//

#ifndef CE_ACTIVIDAD_3_VECTORFUNCTIONS_H
#define CE_ACTIVIDAD_3_VECTORFUNCTIONS_H

#include <vector>

class VectorFunctions {
public:
    static std::vector<double>* add(std::vector<double>* vector1, std::vector<double>* vector2);
    static std::vector<double>* add(std::vector<double>* vector1, double d1);
    static std::vector<double>* mul(std::vector<double>* vector1, std::vector<double>* vector2);
    static std::vector<double>* mul(std::vector<double>* vector1, double d1);
};


#endif //CE_ACTIVIDAD_3_VECTORFUNCTIONS_H
