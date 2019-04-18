//
// Created by alber on 17/04/2019.
//

#ifndef CE_ACTIVIDAD_3_PROBLEM_H
#define CE_ACTIVIDAD_3_PROBLEM_H


#include <vector>

class Problem {
public:
    int numEvaluations;
    Problem();
    double evaluate(std::vector<int> parameters);
    virtual bool isMaximization() = 0;
    virtual double function(std::vector<int> parameters) = 0;
    virtual std::vector<double> decode(std::vector<int> parameters) = 0;
    virtual ~Problem() = default;
};


#endif //CE_ACTIVIDAD_3_PROBLEM_H
