#include <iostream>
#include "src/algorithm/configuration/Configuration.h"
#include "src/algorithm/GeneticAlgorithm.h"

int main() {
    Configuration::loadConfiguration();
    auto* algorithm = new GeneticAlgorithm();
    algorithm->execute();

    delete algorithm;
    delete Configuration::x;
    delete Configuration::problem;
    delete Configuration::selectionParents;
    delete Configuration::reproduction;
    delete Configuration::mutation;
    delete Configuration::selectionSurvivors;
}