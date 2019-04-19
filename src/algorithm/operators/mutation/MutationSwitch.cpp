//
// Created by alber on 15/04/2019.
//

#include "MutationSwitch.h"
#include "../../configuration/Configuration.h"
#include "../../../util/random/RandomGenerator.h"
#include <random>
#include <sstream>

IndividualSet *MutationSwitch::mutate(IndividualSet *set) {
    for(Individual* ind: *set->getSet()){
        this->mutateIndividual(ind);
    }
    return set;
}

void MutationSwitch::mutateIndividual(Individual* ind) {
    for(int i = 0; i < ind->getParam()->size(); i++){
        if(Configuration::pMut >=  RandomGenerator::getDouble(0, 1.0)){
            (*ind->getParam())[i] =  RandomGenerator::getInt(0, Configuration::maxCodonValue);
        }
    }
}


