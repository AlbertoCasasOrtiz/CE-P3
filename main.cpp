#include <iostream>
#include "src/algorithm/configuration/Configuration.h"
#include "src/algorithm/GeneticAlgorithm.h"
#include "src/test/Tests.h"

int main() {
    Configuration::loadConfiguration();
    auto* algorithm = new GeneticAlgorithm();
    algorithm->execute();

    delete algorithm;
    delete Configuration::x;

/*
    Tests tests = Tests();
    tests.testGrammars();
    */
}