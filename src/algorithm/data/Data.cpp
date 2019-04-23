//
// Created by alber on 21/04/2019.
//

#include "Data.h"
#include "../individual/IndividualSet.h"

Data::Data() {
    this->population;
    this->time = 0;
    this->generations = 0;
    this->evaluations = 0;
    this->hits = 0;
}

Data::~Data(){
    delete this->population;
}

void Data::setPopulation(IndividualSet *vector) {
    this->population = vector;
}

void Data::setTime(int value) {
    this->time = value;
}

void Data::setGenerations(int value) {
    this->generations = value;
}

void Data::setEvaluations(int value) {
    this->evaluations = value;
}

void Data::setHits(int value) {
    this->hits = value;
}

IndividualSet *Data::getPopulation() {
    return this->population;
}

int Data::getTime() {
    return this->time;
}

int Data::getGenerations() {
    return this->generations;
}

int Data::getEvaluations() {
    return this->evaluations;
}

int Data::getHits() {
    return this->hits;
}

std::string Data::toString() {
    std::string str;
    str += this->population->getBestIndividual()->toString() + "\n\n";
    str += "Time: " + std::to_string(this->getTime()/60) + "\n";
    str += "Evaluations: " + std::to_string(this->getEvaluations()) + "\n";
    str += "Best Fitness: " + std::to_string(this->population->getBestIndividual()->getFitness()) + "\n";
    str += "Worst Fitness: " + std::to_string(this->population->getWorstIndividual()->getFitness()) + "\n";
    return str;
}




