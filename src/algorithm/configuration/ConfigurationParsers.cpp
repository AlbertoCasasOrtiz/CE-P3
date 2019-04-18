//
// Created by alber on 17/04/2019.
//

#include "ConfigurationParsers.h"
#include "../operators/mutation/MutationSwitch.h"
#include "../operators/reproduction/ReproductionCrossoverOnePoint.h"
#include "../operators/selectionparents/SelectionParentsAllParents.h"
#include "../operators/selectionsurvivors/SelectionSurvivorsGenerational.h"
#include "../problem/ProblemGrammar.h"

int ConfigurationParsers::parseInt(std::string line) {
    return std::stoi(line);
}

double ConfigurationParsers::parseDouble(std::string line){
    return std::stod(line);
}

bool ConfigurationParsers::parseBoolean(std::string line) {
    return line == "true";
}

Problem *ConfigurationParsers::parseProblem(std::string line) {
    if(line == "Grammar") {
        return new ProblemGrammar();
    } else return nullptr;
}

Mutation* ConfigurationParsers::parseMutation(std::string line) {
    if(line == "Switch"){
        return new MutationSwitch();
    } else return nullptr;
}

Reproduction *ConfigurationParsers::parseReproduction(std::string line) {
    if(line == "Crossover One Point"){
        return new ReproductionCrossoverOnePoint();
    } else return nullptr;
}

SelectionParents *ConfigurationParsers::parseSelectionParents(std::string line) {
    if(line == "All Parents"){
        return new SelectionParentsAllParents();
    } else return nullptr;
}

SelectionSurvivors *ConfigurationParsers::parseSelectionSurvivors(std::string line) {
    if(line == "Generational"){
        return new SelectionSurvivorsGenerational();
    } else return nullptr;
}
