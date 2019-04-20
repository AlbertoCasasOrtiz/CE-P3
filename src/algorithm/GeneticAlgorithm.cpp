//
// Created by alber on 13/04/2019.
//

#include "GeneticAlgorithm.h"
#include "configuration/Configuration.h"
#include <algorithm>
#include <iostream>

GeneticAlgorithm::GeneticAlgorithm() {
    this->population = new IndividualSet();
    this->currentGenerations = 0;
    this->elite = new IndividualSet();
    this->timer = new Timer();
}

void GeneticAlgorithm::execute() {
    this->timer->tic();
    for(int i = 0; i < Configuration::numExecutions; i++){
        this->currentGenerations = 0;
        this->population->clear();
        this->population->initialize();
        this->elite->clear();
        while(this->currentGenerations < Configuration::maxNumGenerations){
            auto *parents = new IndividualSet();
            auto *offspring = new IndividualSet();
            this->selectElite();
            parents = Configuration::selectionParents->select(this->population);
            offspring = Configuration::reproduction->reproduce(parents);
            offspring = Configuration::mutation->mutate(offspring);
            offspring->evaluate();
            this->population = Configuration::selectionSurvivors->select(parents, offspring);
            this->population->evaluate();
            this->addEliteToPopulation();
            this->population->increaseAge();
            this->currentGenerations++;
            if(this->currentGenerations % 20 == 0)
                std::cout << this->currentGenerations << std::endl;
            /*if(this->currentGenerations % 100 == 0)
                std::cout << this->population->getBestIndividual()->toString() << std::endl;*/
        }
        this->timer->tac();
        std::cout << "Time: " << this->timer->getTime() << std::endl;
        std::cout << this->population->getBestIndividual()->toString() << std::endl;
    }
}

void GeneticAlgorithm::selectElite() {
    if(Configuration::elitism){
        for(Individual* ind: *this->population->getSet()){
            if(this->elite->sizeOf() < Configuration::numElitism){
                this->elite->addElement(ind);
                //Keep consistency of elite set.
                this->elite->evaluate();
            } else if (this->elite->getBestIndividual()->getFitness() < ind->getFitness()){
                auto it = std::find(this->elite->getSet()->begin(), this->elite->getSet()->end(), this->elite->getWorstIndividual());
                if(it != this->elite->getSet()->end()){
                    int index = std::distance(this->elite->getSet()->begin(), it);
                    (*this->elite->getSet())[index] = ind;
                    //Keep consistency of elite set.
                    this->elite->evaluate();
                } else {
                    //TODO ERROR INDIVIDUAL NOT FOUND
                    std::cout << "Error: Individual not found." << std::endl;
                }
            }
        }
    }
}

void GeneticAlgorithm::addEliteToPopulation() {
    if(Configuration::elitism){
        for(int i = 0; i < this->elite->sizeOf(); i++){
            auto it = std::find(this->population->getSet()->begin(), this->population->getSet()->end(), this->population->getWorstIndividual());
            if(it != this->population->getSet()->end()){
                int index = std::distance(this->population->getSet()->begin(), it);
                (*this->population->getSet())[index] = this->elite->getIndividual(i);
                this->population->consistency();
            } else {
                //TODO ERROR INDIVIDUAL NOT FOUND
            }
        }
    }
}

GeneticAlgorithm::~GeneticAlgorithm() {
    delete this->population;
    delete this->elite;
    delete this->timer;
}
