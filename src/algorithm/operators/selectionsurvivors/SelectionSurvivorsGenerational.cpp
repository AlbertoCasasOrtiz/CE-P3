//
// Created by alber on 15/04/2019.
//

#include "SelectionSurvivorsGenerational.h"

IndividualSet SelectionSurvivorsGenerational::select(IndividualSet parents, IndividualSet offspring) {
    offspring.sort(true);
    std::vector<Individual*>::iterator first = offspring.getSet().begin();
    std::vector<Individual*>::iterator last = offspring.getSet().begin()+30;
    std::vector<Individual*> newPopVector(first, last);
    IndividualSet individualSet = IndividualSet(newPopVector);
    return individualSet;
}
