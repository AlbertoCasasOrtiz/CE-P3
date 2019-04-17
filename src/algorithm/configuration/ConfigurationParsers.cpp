//
// Created by alber on 17/04/2019.
//

#include "ConfigurationParsers.h"
#include "../operators/mutation/MutationSwitch.h"
#include "../operators/reproduction/ReproductionCrossoverOnePoint.h"
#include "../operators/selectionparents/SelectionParentsAllParents.h"
#include "../operators/selectionsurvivors/SelectionSurvivorsGenerational.h"

int ConfigurationParsers::parseInt(std::string line) {
    return std::stoi(line);
}

double ConfigurationParsers::parseDouble(std::string line){
    return std::stod(line);
}

bool ConfigurationParsers::parseBoolean(std::string line) {
    //TODO error if not equal to "true" or "false".
    return line == "true";
}

Mutation* ConfigurationParsers::parseMutation(std::string line) {
    if(line == "Switch"){
        return new MutationSwitch;
    } else return {};
}

Reproduction *ConfigurationParsers::parseReproduction(std::string line) {
    if(line == "Crossover One Point"){
        return new ReproductionCrossoverOnePoint;
    } else return {};
}

SelectionParents *ConfigurationParsers::parseSelectionParents(std::string line) {
    if(line == "All Parents"){
        return new SelectionParentsAllParents;
    } else return {};
}

SelectionSurvivors *ConfigurationParsers::parseSelectionSurvivors(std::string line) {
    if(line == "Generational"){
        return new SelectionSurvivorsGenerational;
    } else return {};
}
