//
// Created by Alberto Casas Ortiz.
//

#include "MutationSwitch.h"
#include "../../configuration/Configuration.h"
#include "../../../util/random/RandomGenerator.h"
#include <random>
#include <sstream>

void MutationSwitch::mutate(IndividualSet *set) {
    for(Individual* ind: *set->getSet()){
        this->mutateIndividual(ind);
    }
}

void MutationSwitch::mutateIndividual(Individual* ind) {
    for(int & pos : *ind->getChromosome()){
        if(Configuration::pMut >=  RandomGenerator::getDouble(0, 1.0)){
            pos =  RandomGenerator::getInt(0, Configuration::maxCodonValue);
        }
    }
}


