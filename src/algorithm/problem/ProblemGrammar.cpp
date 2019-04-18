//
// Created by alber on 17/04/2019.
//

#include "ProblemGrammar.h"
#include "../configuration/Configuration.h"
#include "functions/Functions.h"
#include "functionserror/FunctionsError.h"
#include "grammar/ValuesGrammar.h"
#include "grammar/ExpressionGrammar.h"
#include <limits>

bool ProblemGrammar::isMaximization() {
    return false;
}

double ProblemGrammar::function(std::vector<int> parameters) {
    std::vector<double> result = this->decode(parameters);
    if(!result.empty()){
        std::vector<double> expected = Functions::executeFunction(Configuration::function);
        return FunctionsError::weightedMeanSquaredError(result, expected, 0.1, 1, 10);
    } else return std::numeric_limits<double>::max();

    return 0;
}

std::vector<double> ProblemGrammar::decode(std::vector<int> parameters) {
    ValuesGrammar val = ValuesGrammar(parameters);
    return val.getValues();
}

std::string ProblemGrammar::getExpression(std::vector<int> parameters) {
    ExpressionGrammar exp = ExpressionGrammar(parameters);
    return exp.getExpression();
}

