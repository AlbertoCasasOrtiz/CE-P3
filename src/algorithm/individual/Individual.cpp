//
// Created by alber on 14/04/2019.
//

#include "Individual.h"
#include "../configuration/Configuration.h"
#include "../../util/random/RandomGenerator.h"
#include <random>
#include <sstream>


Individual::Individual() {
    this->params = new std::vector<int>();
    this->fitness = 0;
    this->probability = 0;
    this->accumulatedProbability = 0;
    this->age = 0;
}

void Individual::initialize() {
    int size = RandomGenerator::getInt(1, Configuration::maxChromosomeSize);
    for(int i = 0; i < size; i++){
        this->params->push_back(RandomGenerator::getInt(1, Configuration::maxCodonValue));
    }
}

void Individual::evaluate() {
    this->fitness = Configuration::problem->evaluate(this->params);
    this->expression = Configuration::problem->getExpression(this->params);
}

std::vector<double>* Individual::getFenotype() {
    return Configuration::problem->decode(this->params);
}
int Individual::sizeOf() {
    return this->params->size();
}

int Individual::getAge() {
    return this->age;
}

void Individual::increaseAge() {
    this->age++;
}

std::vector<int>* Individual::getParam() {
    return this->params;
}

void Individual::addParam(int object) {
    this->params->push_back(object);
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
    for(int param : *this->params){
        ind->params->push_back(param);
    }
    return ind;
}

std::string Individual::toString() {
    std::vector<double>* fenotype = this->getFenotype();
    std::ostringstream str;
    str << "Fitness: " << this->fitness << "\n";
    str << "Probability: " << this->probability << "\n";
    str << "Accum. Probability: " << this->accumulatedProbability << "\n";
    str << "Age: " << this->age << "\n";
    str << "Genotype: " << "\n";
    for(int param : *this->params){
        str << param << " ";
    }
    str << "\n";
    for(double param : *fenotype){
        str << param << " ";
    }
    str << "\n";
    return std::string();
}

std::string Individual::getExpression() {
    return Configuration::problem->getExpression(this->params);
}


