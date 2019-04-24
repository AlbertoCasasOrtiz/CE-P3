//
// Created by Alberto Casas Ortiz.
//

#include "ExecutionData.h"
#include "../individual/IndividualSet.h"

ExecutionData::ExecutionData() {
    this->time = 0;
    this->generations = 0;
    this->evaluations = 0;
    this->hits = 0;
}

ExecutionData::~ExecutionData(){
    delete this->population;
}

void ExecutionData::setPopulation(IndividualSet *vector) {
    this->population = vector;
}

void ExecutionData::setTime(double value) {
    this->time = value;
}

void ExecutionData::setGenerations(int value) {
    this->generations = value;
}

void ExecutionData::setEvaluations(int value) {
    this->evaluations = value;
}

void ExecutionData::setHits(int value) {
    this->hits = value;
}

IndividualSet *ExecutionData::getPopulation() {
    return this->population;
}

double ExecutionData::getTime() {
    return this->time;
}

int ExecutionData::getGenerations() {
    return this->generations;
}

int ExecutionData::getEvaluations() {
    return this->evaluations;
}

int ExecutionData::getHits() {
    return this->hits;
}

std::string ExecutionData::toString() {
    std::string str;
    str += this->population->getBestIndividual()->toString() + "\n\n";
    str += "Time: " + std::to_string(this->getTime()) + "\n";
    str += "Evaluations: " + std::to_string(this->getEvaluations()) + "\n";
    str += "Generations: " + std::to_string(this->getGenerations()) + "\n";
    str += "Best Fitness: " + std::to_string(this->population->getBestIndividual()->getFitness()) + "\n";
    str += "Worst Fitness: " + std::to_string(this->population->getWorstIndividual()->getFitness()) + "\n";
    return str;
}




