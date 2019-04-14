//
// Created by alber on 14/04/2019.
//

#include "Individual.h"
#include "../configuration/Configuration.h"
#include <random>
#include <sstream>


Individual::Individual() {
    this->params = std::vector<int>();
    this->fitness = 0;
    this->probability = 0;
    this->accumulatedProbability = 0;
    this->age = 0;
    //Initialize random seed.
}

void Individual::initialize() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distCodon(1, Configuration::maxCodonValue);
    std::uniform_int_distribution<int> distSize(1, Configuration::maxChromosomeSize);
    int size = distSize(mt);
    for(int i = 0; i < size; i++){
        this->params.push_back(distCodon(mt));
    }
}

void Individual::evaluate() {
    //TODO Call problem in configuration.
    //this->fitness = Configuration::problem->evaluate(this->params);

}

std::vector<double> Individual::getFenotype() {
    //TODO return grammar interpreted.
    return std::vector<double>();
}
int Individual::sizeOf() {
    return this->params.size();
}

int Individual::getAge() {
    return this->age;
}

void Individual::increaseAge() {
    this->age++;
}

std::vector<int> Individual::getParam() {
    return this->params;
}

void Individual::addParam(int object) {
    this->params.push_back(object);
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

Individual Individual::copy() {
    Individual ind = Individual();
    ind.fitness = this->fitness;
    ind.probability = this->probability;
    ind.accumulatedProbability = this->accumulatedProbability;
    ind.age = this->age;
    for(int param : this->params){
        ind.params.push_back(param);
    }
    return ind;
}

std::string Individual::toString() {
    std::vector<double> fenotype = this->getFenotype();
    std::ostringstream str;
    str << "Fitness: " << this->fitness << "\n";
    str << "Probability: " << this->probability << "\n";
    str << "Accum. Probability: " << this->accumulatedProbability << "\n";
    str << "Age: " << this->age << "\n";
    str << "Genotype: " << "\n";
    for(int param : this->params){
        str << param << " ";
    }
    str << "\n";
    for(double param : fenotype){
        str << param << " ";
    }
    str << "\n";
    return std::string();
}

