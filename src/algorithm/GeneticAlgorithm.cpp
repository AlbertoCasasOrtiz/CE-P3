//
// Created by Alberto Casas Ortiz.
//

#include "GeneticAlgorithm.h"
#include "configuration/Configuration.h"
#include "qualitymeasures/QualityMeasures.h"
#include "problem/functions/Functions.h"
#include "data/writefile/WriteResultsInFile.h"
#include <algorithm>
#include <iostream>

int GeneticAlgorithm::evaluations;
int GeneticAlgorithm::currentGenerations;

GeneticAlgorithm::GeneticAlgorithm() {
    this->population = new IndividualSet();
    GeneticAlgorithm::currentGenerations = 0;
    GeneticAlgorithm::evaluations = 0;
    this->elite = nullptr;
    this->timer = new Timer();
    this->dataSet = new DataSet();
}

void GeneticAlgorithm::execute() {
    IndividualSet *parents;
    IndividualSet *offspring;
    for(int i = 0; i < Configuration::numExecutions; i++){
        this->timer->tic();
        GeneticAlgorithm::currentGenerations = 0;
        GeneticAlgorithm::evaluations = 0;
        this->population->clear();
        this->population->initialize();
        while(GeneticAlgorithm::currentGenerations < Configuration::maxNumGenerations){
            this->elite = this->selectElite();
            parents = Configuration::selectionParents->select(this->population);
            offspring = Configuration::reproduction->reproduce(parents);
            Configuration::mutation->mutate(offspring);
            offspring->evaluate(true);
            delete this->population;
            this->population = Configuration::selectionSurvivors->select(parents, offspring);
            delete parents;
            delete offspring;
            this->population->evaluate(false);
            this->addEliteToPopulation();
            this->population->increaseAge();
            GeneticAlgorithm::currentGenerations++;

            if(GeneticAlgorithm::currentGenerations % 50 == 0) {
                std::cout << (100*GeneticAlgorithm::currentGenerations)/Configuration::maxNumGenerations << "%" << std::endl;
            }
            delete this->elite;
        }

        this->timer->tac();
        auto* data = new ExecutionData();
        data->setPopulation(this->population->copy());
        data->setGenerations(GeneticAlgorithm::currentGenerations);
        data->setHits(QualityMeasures::numHits(data));
        data->setTime(this->timer->getTime());
        data->setEvaluations(GeneticAlgorithm::evaluations);
        data->setHits(QualityMeasures::numHits(data));
        data->setSuccessRate(QualityMeasures::successRate(data));
        data->setName("Execution_" + std::to_string(i));
        dataSet->addData(data);
        WriteResultsInFile::writeResults(data);
    }
}

IndividualSet* GeneticAlgorithm::selectElite() {
    auto* newElite = new IndividualSet();
    if(Configuration::elitism){
        for(Individual* ind: *this->population->getSet()){
            if(newElite->sizeOf() < Configuration::numElitism){
                newElite->addElement(ind->copy());
                //Keep consistency of elite set.
                newElite->consistency();
            } else if (newElite->getBestIndividual()->getFitness() < ind->getFitness()){
                auto it = std::find(newElite->getSet()->begin(), newElite->getSet()->end(), newElite->getWorstIndividual());
                if(it != newElite->getSet()->end()){
                    int index = std::distance(newElite->getSet()->begin(), it);
                    (*newElite->getSet())[index] = ind->copy();
                    //Keep consistency of elite set.
                    newElite->consistency();
                } else {
                    std::cerr << "Error: Individual not found." << std::endl;
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
                std::cerr << "Error: Individual not found." << std::endl;
            }
        }
    }
}

GeneticAlgorithm::~GeneticAlgorithm() {
    delete this->population;
    delete this->timer;
    delete this->dataSet;
}
