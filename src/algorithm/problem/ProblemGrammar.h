//
// Created by alber on 17/04/2019.
//

#ifndef CE_ACTIVIDAD_3_PROBLEMGRAMMAR_H
#include "Problem.h"
#include <string>
#define CE_ACTIVIDAD_3_PROBLEMGRAMMAR_H


class ProblemGrammar: public Problem{
public:
    bool isMaximization() override;
    double function(std::vector<int>* parameters) override;
    std::vector<double>* decode(std::vector<int>* parameters) override;
    std::string getExpression(std::vector<int>* parameters) override;
    ~ProblemGrammar() override = default;
};


#endif //CE_ACTIVIDAD_3_PROBLEMGRAMMAR_H
