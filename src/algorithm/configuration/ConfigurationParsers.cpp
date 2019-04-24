//
// Created by Alberto Casas Ortiz.
//

#include "ConfigurationParsers.h"
#include "../operators/mutation/MutationSwitch.h"
#include "../operators/reproduction/ReproductionCrossoverOnePoint.h"
#include "../operators/selectionparents/SelectionParentsAllParents.h"
#include "../operators/selectionsurvivors/SelectionSurvivorsGenerational.h"
#include "../problem/ProblemGrammar.h"
#include "../operators/reproduction/ReproductionCrossoverTwoPoints.h"

int ConfigurationParsers::parseInt(const std::string& line) {
    return std::stoi(line);
}

double ConfigurationParsers::parseDouble(const std::string& line){
    return std::stod(line);
}

bool ConfigurationParsers::parseBoolean(const std::string& line) {
    return line == "true";
}

Problem *ConfigurationParsers::parseProblem(const std::string& line) {
    if(line == "Grammar") {
        return new ProblemGrammar();
    } else return nullptr;
}

Mutation* ConfigurationParsers::parseMutation(const std::string& line) {
    if(line == "Switch"){
        return new MutationSwitch();
    } else return nullptr;
}

Reproduction *ConfigurationParsers::parseReproduction(const std::string& line) {
    if(line == "Crossover One Point") {
        return new ReproductionCrossoverOnePoint();
    }else if(line == "Crossover Two Point"){
            return new ReproductionCrossoverTwoPoints();
    } else return nullptr;
}

SelectionParents *ConfigurationParsers::parseSelectionParents(const std::string& line) {
    if(line == "All Parents"){
        return new SelectionParentsAllParents();
    } else return nullptr;
}

SelectionSurvivors *ConfigurationParsers::parseSelectionSurvivors(const std::string& line) {
    if(line == "Generational"){
        return new SelectionSurvivorsGenerational();
    } else return nullptr;
}
