//
// Created by alber on 17/04/2019.
//

#ifndef CE_ACTIVIDAD_3_FUNCTIONSERROR_H
#define CE_ACTIVIDAD_3_FUNCTIONSERROR_H


#include <vector>
#include <cmath>
#include <stdlib.h>

class FunctionsError {
public:
    static double weightedMeanSquaredError(std::vector<double>* f1, std::vector<double>* f2, double u, double k0, double k1);
};


#endif //CE_ACTIVIDAD_3_FUNCTIONSERROR_H
