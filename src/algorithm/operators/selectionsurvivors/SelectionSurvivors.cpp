//
// Created by alber on 15/04/2019.
//

#include "SelectionSurvivors.h"

IndividualSet SelectionSurvivors::select(IndividualSet parents, IndividualSet offspring) {
    offspring.sort(true);
    std::vector<Individual>::iterator first = offspring.getSet().begin();
    std::vector<Individual>::iterator last = offspring.getSet().begin()+30;
    std::vector<Individual> newPop(first, last);
    return newPop;
}
