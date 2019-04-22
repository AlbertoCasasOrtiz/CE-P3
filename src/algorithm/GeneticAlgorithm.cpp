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
    this->dataSet = new DataSet();
}

void GeneticAlgorithm::execute() {
    IndividualSet *parents;
    IndividualSet *offspring;
    this->timer->tic();
    for(int i = 0; i < Configuration::numExecutions; i++){
        this->currentGenerations = 0;
        this->population->clear();
        this->population->initialize();
        this->elite->clear();
        while(this->currentGenerations < Configuration::maxNumGenerations){
            delete this->elite;
            this->elite = this->selectElite();
            this->selectElite();
            parents = Configuration::selectionParents->select(this->population);
            offspring = Configuration::reproduction->reproduce(parents);
            Configuration::mutation->mutate(offspring);
            offspring->evaluate();
            delete this->population;
            this->population = Configuration::selectionSurvivors->select(parents, offspring);
            delete parents;
            delete offspring;
            this->population->evaluate();
            this->addEliteToPopulation();
            this->population->increaseAge();
            this->currentGenerations++;
            if(this->currentGenerations % 20 == 0)
                std::cout << this->currentGenerations << std::endl;
        }
        this->timer->tac();
        std::cout << "Time: " << this->timer->getTime() << std::endl;
        std::cout << this->population->getBestIndividual()->toString() << std::endl;

        Data* data = new Data();
        data->setPopulation(this->population->clone());
        data->setGenerations(this->currentGenerations);
        data->setTime(this->timer->getTime());
        //TODO NUMBER OF EVALUATIONS.
        //data->setEvaluations()
        //TODO NUMBER OF HITS
        //data->setHits()
        dataSet->addData(data);
    }
    //TODO OUT DATASET
    delete this->dataSet;
}

IndividualSet* GeneticAlgorithm::selectElite() {
    auto* newElite = new IndividualSet();
    if(Configuration::elitism){
        for(Individual* ind: *this->population->getSet()){
            if(newElite->sizeOf() < Configuration::numElitism){
                newElite->addElement(ind->copy());
                //Keep consistency of elite set.
                newElite->evaluate();
            } else if (newElite->getBestIndividual()->getFitness() < ind->getFitness()){
                auto it = std::find(newElite->getSet()->begin(), newElite->getSet()->end(), newElite->getWorstIndividual());
                if(it != newElite->getSet()->end()){
                    int index = std::distance(newElite->getSet()->begin(), it);
                    (*newElite->getSet())[index] = ind->copy();
                    //Keep consistency of elite set.
                    newElite->evaluate();
                } else {
                    //TODO ERROR INDIVIDUAL NOT FOUND
                    std::cout << "Error: Individual not found." << std::endl;
                }
            }
        }
    }
    return newElite;
}

void GeneticAlgorithm::addEliteToPopulation() {
    if(Configuration::elitism){
        for(int i = 0; i < this->elite->sizeOf(); i++){
            auto it = std::find(this->population->getSet()->begin(), this->population->getSet()->end(), this->population->getWorstIndividual());
            if(it != this->population->getSet()->end()){
                int index = std::distance(this->population->getSet()->begin(), it);
                (*this->population->getSet())[index] = this->elite->getIndividual(i)->copy();
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
    delete this->dataSet;
}
