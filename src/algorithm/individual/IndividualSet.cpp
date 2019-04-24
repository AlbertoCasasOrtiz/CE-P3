#include <utility>

//
// Created by alber on 14/04/2019.
//

#include "IndividualSet.h"
#include "../configuration/Configuration.h"
#include "../GeneticAlgorithm.h"
#include <limits>
#include <iostream>
#include <algorithm>

void IndividualSet::sort(bool ascendent) {
    if (ascendent) {
        std::sort(this->set->begin(), this->set->end(), comparatorAscendant);
    } else {
        std::sort(this->set->begin(), this->set->end(), comparatorDescendant);
    }

}

bool IndividualSet::comparatorAscendant(Individual *i1, Individual *i2) {
    return i1->getFitness() > i2->getFitness();
}

bool IndividualSet::comparatorDescendant(Individual *i1, Individual *i2) {
    return i1->getFitness() < i2->getFitness();
}

IndividualSet::IndividualSet() {
    this->set = new std::vector<Individual*>();
    averageFitness = 0.0;
    this->bestIndividual = nullptr;
    this->worstIndividual = nullptr;
}

IndividualSet::~IndividualSet() {
    for(auto & ind : *this->set)
        delete ind;
    delete this->set;
}

IndividualSet::IndividualSet(std::vector<Individual*>* set) {
    this->set = set;
    averageFitness = 0.0;
    bestIndividual = new Individual();
    worstIndividual = new Individual();
}

void IndividualSet::initialize() {
    Individual* ind;
    for(int i = 0; i < Configuration::populationSize; i++){
        ind = new Individual();
        ind->initialize();
        this->set->push_back(ind);
    }
    this->evaluate(true);
}

void IndividualSet::evaluate(bool count) {
    for(Individual* ind: *this->set){
        ind->evaluate();
        if(count)
            GeneticAlgorithm::evaluations++;
    }
    this->consistency();
}

void IndividualSet::consistency() {
    double bestFitness = std::numeric_limits<double>::lowest();
    double worstFitness = std::numeric_limits<double>::infinity();
    this->averageFitness = 0.0;
    for(Individual* ind: *this->set){
        this->averageFitness += ind->getFitness();
        this->bestIndividual = ind->getFitness() >= bestFitness ? ind : this->bestIndividual;
        bestFitness = bestIndividual->getFitness();
        this->worstIndividual = ind->getFitness() <= worstFitness ? ind : this->worstIndividual;
        worstFitness = worstIndividual->getFitness();
    }
    this->averageFitness /= this->set->size();
}

void IndividualSet::increaseAge() {
    for(Individual* ind: *this->set)
        ind->increaseAge();
}

int IndividualSet::sizeOf() {
    return set->size();
}

void IndividualSet::clear() {
    this->set->clear();
    this->averageFitness = 0.0;
    this->bestIndividual = nullptr;
    this->worstIndividual = nullptr;
}

void IndividualSet::addElement(Individual* ind) {
    this->set->push_back(ind);
}

void IndividualSet::addElements(std::vector<Individual*>* set1) {
    for(auto ind : *set1){
        this->set->push_back(ind);
    }
}

void IndividualSet::addElements(IndividualSet *set1) {
    this->addElements(set1->getSet());
}

std::vector<Individual*>* IndividualSet::getSet() {
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
    return this->set->at(i);
}

IndividualSet *IndividualSet::clone() {
    auto* individualSet = new IndividualSet();
    for(int i = 0; i < this->sizeOf(); i++){
        individualSet->set->push_back(this->set->at(i)->copy());
    }
    //Best individual, worst individual and average fitness are declared
    //in the function consistency using data from the set.
    individualSet->consistency();
    return individualSet;
}
