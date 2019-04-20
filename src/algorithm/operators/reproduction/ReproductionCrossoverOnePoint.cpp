//
// Created by alber on 15/04/2019.
//

#include "ReproductionCrossoverOnePoint.h"
#include "../../configuration/Configuration.h"
#include "../../../util/random/RandomGenerator.h"

IndividualSet *ReproductionCrossoverOnePoint::reproduce(IndividualSet *parents) {

    auto *offspring = new IndividualSet();
    while(offspring->sizeOf() < Configuration::offspringSize){
        int pos1 = RandomGenerator::getInt(0, parents->sizeOf());
        int pos2 = RandomGenerator::getInt(0, parents->sizeOf());
        if(Configuration::pRep >= RandomGenerator::getDouble(0.0, 1.0)){
            IndividualSet *generated = this->crossover(parents->getIndividual(pos1)->copy(), parents->getIndividual(pos2)->copy());
            offspring->addElements(generated);
        } else {
            offspring->addElement(parents->getIndividual(pos1)->copy());
            offspring->addElement(parents->getIndividual(pos2)->copy());
        }
    }
    return offspring;
}

IndividualSet *ReproductionCrossoverOnePoint::crossover(Individual* i1, Individual* i2) {
    auto *indSet = new IndividualSet();
    int point1 = RandomGenerator::getInt(0, i1->sizeOf());
    int point2 = RandomGenerator::getInt(0, i2->sizeOf());

    Individual *ind1 = this->createIndividual(i1, i2, point1, point2);
    Individual *ind2 = this->createIndividual(i2, i1, point2, point1);

    if(ind1->getParam()->size() < Configuration::maxChromosomeSize){
        indSet->addElement(ind1);
        delete i1;
    } else {
        indSet->addElement(i1);
        delete ind1;
    }


    if(ind2->getParam()->size() < Configuration::maxChromosomeSize){
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
        ind->getParam()->push_back((*i1->getParam())[i]);
    }
    for(int i = point2; i < i2->sizeOf(); i++){
        ind->getParam()->push_back((*i2->getParam())[i]);
    }
    return ind;
}

