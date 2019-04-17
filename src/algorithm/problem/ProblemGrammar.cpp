//
// Created by alber on 17/04/2019.
//

#include "ProblemGrammar.h"
#include "../configuration/Configuration.h"
#include "functions/Functions.h"
#include "functionserror/FunctionsError.h"

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
    //TODO NECESARIO GRAMMAR
    return std::vector<double>();
}

std::string ProblemGrammar::getExpression(std::vector<int> parameters) {
    //TODO NECESARIO GRAMMAR
    return std::string();
}

