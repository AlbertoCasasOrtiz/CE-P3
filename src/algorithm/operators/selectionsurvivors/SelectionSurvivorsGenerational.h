//
// Created by alber on 15/04/2019.
//

#ifndef CE_ACTIVIDAD_3_SELECTIONSURVIVORSGENERATIONAL_H
#include "../../individual/IndividualSet.h"
#include "SelectionSurvivors.h"

#define CE_ACTIVIDAD_3_SELECTIONSURVIVORSGENERATIONAL_H



class SelectionSurvivorsGenerational: public SelectionSurvivors{
public:
    IndividualSet select(IndividualSet parents, IndividualSet offspring) override;
};


#endif //CE_ACTIVIDAD_3_SELECTIONSURVIVORSGENERATIONAL_H
