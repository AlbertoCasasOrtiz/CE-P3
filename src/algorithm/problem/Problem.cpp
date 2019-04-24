//
// Created by Alberto Casas Ortiz.
//

#include <iostream>
#include "Problem.h"

double Problem::evaluate(std::vector<int>* parameters) {
    return isMaximization() ? function(parameters) : -function(parameters);
}

