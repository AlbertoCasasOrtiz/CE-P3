//
// Created by alber on 15/04/2019.
//

#include "MutationSwitch.h"
#include "../../configuration/Configuration.h"
#include <random>
#include <sstream>

IndividualSet MutationSwitch::mutate(IndividualSet set) {
    for(Individual ind: set.getSet()){
        this->mutateIndividual(ind);
    }
    return set;
}

void MutationSwitch::mutateIndividual(Individual ind) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> distPMut(0.0, 1.0);
    std::uniform_int_distribution<int> distCodon(1, Configuration::maxCodonValue);
    for(int i = 0; i < ind.getParam().size(); i++){
        if(Configuration::pMut >= distPMut(mt)){
            ind.getParam()[i] = distCodon(mt);
        }
    }
}


