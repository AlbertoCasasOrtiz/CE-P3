//
// Created by alber on 13/04/2019.
//

#include "GeneticAlgorithm.h"
#include "configuration/Configuration.h"
#include <algorithm>

GeneticAlgorithm::GeneticAlgorithm() {
    this->population = IndividualSet();
    this->currentGenerations = 0;
    this->elite = IndividualSet();
}

void GeneticAlgorithm::execute() {
    for(int i = 0; i < Configuration::numExecutions; i++){
        this->currentGenerations = 0;
        this->population.clear();
        this->population.initialize();
        this->elite.clear();
        while(this->currentGenerations < Configuration::maxNumGenerations){
            this->selectElite();
            IndividualSet parents = Configuration::selectionParents->select(this->population);
            IndividualSet offspring = Configuration::reproduction->reproduce(parents);
            offspring = Configuration::mutation->mutate(offspring);
            offspring.evaluate();
            this->population = Configuration::selectionSurvivors->select(parents, offspring);

            this->addEliteToPopulation();
            this->population.increaseAge();
            this->currentGenerations++;
        }
    }
}

void GeneticAlgorithm::selectElite() {
    if(Configuration::elitism){
        for(Individual* ind: this->population.getSet()){
            if(this->elite.sizeOf() < Configuration::numElitism){
                this->elite.addElement(ind);
            } else if (this->elite.getBestIndividual()->getFitness() < ind->getFitness()){
                auto it = std::find(this->elite.getSet().begin(), this->elite.getSet().end(), this->elite.getWorstIndividual());
                if(it != this->elite.getSet().end()){
                    int index = std::distance(this->elite.getSet().begin(), it);
                    this->elite.getSet()[index] = ind;
                } else {
                    //TODO ERROR INDIVIDUAL NOT FOUND
                }
                this->elite.evaluate();
            }
        }
    }
}

void GeneticAlgorithm::addEliteToPopulation() {
    if(Configuration::elitism){
        for(int i = 0; i < this->elite.sizeOf(); i++){
            auto it = std::find(this->population.getSet().begin(), this->population.getSet().end(), this->population.getWorstIndividual());
            if(it != this->population.getSet().end()){
                int index = std::distance(this->population.getSet().begin(), it);
                this->population.getSet()[index] = this->elite.getIndividual(i);
            } else {
                //TODO ERROR INDIVIDUAL NOT FOUND
            }
        }
    }
}
