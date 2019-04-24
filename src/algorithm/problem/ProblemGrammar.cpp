//
// Created by Alberto Casas Ortiz.
//

#include "ProblemGrammar.h"
#include "../configuration/Configuration.h"
#include "functions/Functions.h"
#include "functionserror/FunctionsError.h"
#include "grammar/ValuesGrammar.h"
#include "grammar/ExpressionGrammar.h"
#include <limits>
#include <iostream>

bool ProblemGrammar::isMaximization() {
    return false;
}

double ProblemGrammar::function(std::vector<int>* parameters) {
    std::vector<double>* result = this->decode(parameters);
    if(!result->empty()){
        std::vector<double>* expected = Functions::executeFunction(Configuration::function);
        double res = FunctionsError::weightedMeanSquaredError(result, expected, 0.1, 1, 10);
        delete result;
        delete expected;
        return res;
    } else{
        delete result;
        return std::numeric_limits<double>::max();
    }
}

std::vector<double>* ProblemGrammar::decode(std::vector<int>* parameters) {
    ValuesGrammar val = ValuesGrammar(new std::vector<int>(*parameters));
    return val.getValues();
}

std::string ProblemGrammar::getExpression(std::vector<int>* parameters) {
    ExpressionGrammar exp = ExpressionGrammar(new std::vector<int>(*parameters));
    return exp.getExpression();
}

