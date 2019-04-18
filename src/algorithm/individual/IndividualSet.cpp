#include <utility>

//
// Created by alber on 14/04/2019.
//

#include "IndividualSet.h"
#include "../configuration/Configuration.h"
#include <limits>

void IndividualSet::sort(bool ascendent) {
    //TODO MIRAR EJEMPLO 3 DE ESTA PAGINA https://www.geeksforgeeks.org/sorting-a-vector-in-c/
}

IndividualSet::IndividualSet() {
    this->set = std::vector<Individual*>();
    averageFitness = 0.0;
    bestIndividual = new Individual();
    worstIndividual = new Individual();
}

IndividualSet::~IndividualSet() {
    delete this->bestIndividual;
    delete this->worstIndividual;
}

IndividualSet::IndividualSet(std::vector<Individual*> set) {
    this->set = std::move(set);
    averageFitness = 0.0;
    bestIndividual = new Individual();
    worstIndividual = new Individual();
}

void IndividualSet::initialize() {
    for(int i = 0; i < Configuration::populationSize; i++){
        auto* ind = new Individual();
        ind->initialize();
        this->set.push_back(ind);
    }
    this->evaluate();
}

void IndividualSet::evaluate() {
    double bestFitness = std::numeric_limits<double>::min();
    double worstFitness = std::numeric_limits<double>::max();
    this->averageFitness = 0.0;
    for(Individual* ind: this->set){
        ind->evaluate();
        this->averageFitness += ind->getFitness();
        this->bestIndividual = ind->getFitness() >= bestFitness ? ind : this->bestIndividual;
        bestFitness = bestIndividual->getFitness();
        this->worstIndividual = ind->getFitness() <= worstFitness ? ind : this->worstIndividual;
        worstFitness = worstIndividual->getFitness();
    }
    this->averageFitness /= this->set.size();
}

void IndividualSet::increaseAge() {
    for(Individual* ind: this->set)
        ind->increaseAge();
}

int IndividualSet::sizeOf() {
    return set.size();
}

void IndividualSet::clear() {
    this->set.clear();
    this->averageFitness = 0.0;
    delete this->bestIndividual;
    delete this->worstIndividual;
}

void IndividualSet::addElement(Individual* ind) {
    this->set.push_back(ind);
}

void IndividualSet::addElements(std::vector<Individual*> set1) {
    this->set.insert(set1.end(), set1.begin(), set1.end());
}

void IndividualSet::addElements(IndividualSet set1) {
    this->addElements(set1.getSet());
}

std::vector<Individual*> IndividualSet::getSet() {
    return this->set;
}

double IndividualSet::getAverageFitness() {
    return this->averageFitness;
}

Individual* IndividualSet::getBestIndividual() {
    return this->bestIndividual;
}

Individual* IndividualSet::getWorstIndividual() {
    return this->worstIndividual;
}

Individual* IndividualSet::getIndividual(int i) {
    return this->set.at(i);
}

std::string IndividualSet::toString() {
    //TODO TOSTRING
    return std::string();
}
