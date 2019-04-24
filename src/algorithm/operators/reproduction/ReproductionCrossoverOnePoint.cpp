//
// Created by Alberto Casas Ortiz.
//

#include "ReproductionCrossoverOnePoint.h"
#include "../../configuration/Configuration.h"
#include "../../../util/random/RandomGenerator.h"

IndividualSet *ReproductionCrossoverOnePoint::reproduce(IndividualSet *parents) {
    auto *offspring = new IndividualSet();
    while(offspring->sizeOf() < Configuration::offspringSize){
        /**Select individuals to reproduce. */
        int pos1 = RandomGenerator::getInt(0, parents->sizeOf());
        int pos2 = RandomGenerator::getInt(0, parents->sizeOf());
        /** Check if they will reproduce. */
        if(Configuration::pRep >= RandomGenerator::getDouble(0.0, 1.0)){
            IndividualSet *generated = this->crossover(parents->getIndividual(pos1)->copy(), parents->getIndividual(pos2)->copy());
            offspring->addElement(generated->getSet()->at(0)->copy());
            offspring->addElement(generated->getSet()->at(1)->copy());
            delete generated;
        } else {
            offspring->addElement(parents->getIndividual(pos1)->copy());
            offspring->addElement(parents->getIndividual(pos2)->copy());
        }
    }
    return offspring;
}

IndividualSet *ReproductionCrossoverOnePoint::crossover(Individual* i1, Individual* i2) {
    auto *indSet = new IndividualSet();

    int point1 = RandomGenerator::getInt(0, floor(i1->sizeOf()));
    int point2 = RandomGenerator::getInt(0, floor(i2->sizeOf()));

    Individual *ind1 = this->createIndividual(i1, i2, point1, point2);
    Individual *ind2 = this->createIndividual(i2, i1, point2, point1);

    /** If the size is valid, use the individual, if not, use parent. */
    if(ind1->getChromosome()->size() < Configuration::maxChromosomeSize){
        indSet->addElement(ind1);
        delete i1;
    } else {
        indSet->addElement(i1);
        delete ind1;
    }

    /** If the size is valid, use the individual, if not, use parent. */
    if(ind2->getChromosome()->size() < Configuration::maxChromosomeSize){
        indSet->addElement(ind2);
        delete i2;
    } else {
        indSet->addElement(i2);
        delete ind2;
    }

    return indSet;
}

Individual* ReproductionCrossoverOnePoint::createIndividual(Individual* i1, Individual* i2, int point1, int point2) {
    auto *ind = new Individual();
    for(int i = 0; i < point1; i++){
        ind->getChromosome()->push_back((*i1->getChromosome())[i]);
    }
    for(int i = point2; i < i2->sizeOf(); i++){
        ind->getChromosome()->push_back((*i2->getChromosome())[i]);
    }
    return ind;
}

