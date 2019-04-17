//
// Created by alber on 17/04/2019.
//

#include "Problem.h"

Problem::Problem() {
    this->numEvaluations = 0;
}

double Problem::evaluate(std::vector<int> parameters) {
    this->numEvaluations++;
    return isMaximization() ? function(parameters) : -function(parameters);
}

