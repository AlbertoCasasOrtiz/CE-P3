#include <iostream>
#include "src/algorithm/configuration/Configuration.h"
#include "src/algorithm/GeneticAlgorithm.h"

int main() {
    Configuration::loadConfiguration();
    GeneticAlgorithm algorithm = GeneticAlgorithm();
    algorithm.execute();
}