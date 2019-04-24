//
// Created by Alberto Casas Ortiz.
//

#include "Individual.h"
#include "../configuration/Configuration.h"
#include "../../util/random/RandomGenerator.h"
#include "../problem/functions/Functions.h"
#include <random>
#include <sstream>
#include <iostream>


Individual::Individual() {
    this->chromosome = new std::vector<int>();
    this->fitness = 0;
    this->probability = 0;
    this->accumulatedProbability = 0;
    this->age = 0;
}

Individual::~Individual() {
    delete this->chromosome;
}

void Individual::initialize() {
    //Generate a random size for the individual.
    int size = RandomGenerator::getInt(1, Configuration::maxChromosomeSize);
    for(int i = 0; i < size; i++){
        //Insert random codons in the individual.
        this->chromosome->push_back(RandomGenerator::getInt(1, Configuration::maxCodonValue));
    }
}

void Individual::evaluate() {
    this->fitness = Configuration::problem->evaluate(this->chromosome);
    this->expression = Configuration::problem->getExpression(this->chromosome);
}

std::vector<double>* Individual::getFenotype() {
    return Configuration::problem->decode(this->chromosome);
}

int Individual::sizeOf() {
    return this->chromosome->size();
}

int Individual::getAge() {
    return this->age;
}

void Individual::increaseAge() {
    this->age++;
}

std::vector<int>* Individual::getChromosome() {
    return this->chromosome;
}

void Individual::addCodon(int object) {
    this->chromosome->push_back(object);
}

double Individual::getProbability() {
    return this->probability;
}

void Individual::setProbability(double prob) {
    this->probability = prob;
}

double Individual::getAccumulatedProbability() {
    return this->accumulatedProbability;
}

void Individual::setAccumulatedProbability(double accumProb) {
    this->accumulatedProbability = accumProb;
}

void Individual::setProbabilities(double prob, double accumProb) {
    this->probability = prob;
    this->accumulatedProbability = accumProb;
}

void Individual::setFitness(double f) {
    this->fitness = f;
}

double Individual::getFitness() {
    return this->fitness;
}

Individual* Individual::copy() {
    auto* ind = new Individual();
    ind->fitness = this->fitness;
    ind->probability = this->probability;
    ind->accumulatedProbability = this->accumulatedProbability;
    ind->age = this->age;
    for(int param : *this->chromosome){
        ind->chromosome->push_back(param);
    }
    return ind;
}

std::string Individual::toString() {
    std::ostringstream str;
    str << "Fitness: " << this->fitness << "\n";
    str << "Probability: " << this->probability << "\n";
    str << "Accum. Probability: " << this->accumulatedProbability << "\n";
    str << "Age: " << this->age << "\n";
    str << "Expression: " << this->getExpression() << std::endl;
    str << "Genotype: " << "\n";
    for(int param : *this->chromosome){
        str << param << " ";
    }
    str << "\n";
    str << "Result: " << "\n";
    std::vector<double>* fenotype = this->getFenotype();
    for(double param : *fenotype){
        str << param << "\n";
    }
    delete fenotype;
    str << "\n";
    str << "Expected: " << "\n";
    std::vector<double>* expected = Functions::executeFunction(Configuration::function);
    for(double xi : *expected){
        str << xi << "\n";
    }
    delete expected;
    return str.str();
}

std::string Individual::getExpression() {
    return Configuration::problem->getExpression(this->chromosome);
}
