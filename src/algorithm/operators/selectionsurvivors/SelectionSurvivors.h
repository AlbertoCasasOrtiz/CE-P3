//
// Created by alber on 15/04/2019.
//

#ifndef CE_ACTIVIDAD_3_SELECTIONSURVIVORS_H
#define CE_ACTIVIDAD_3_SELECTIONSURVIVORS_H


#include "../../individual/IndividualSet.h"

class SelectionSurvivors {
public:
    virtual IndividualSet select(IndividualSet parents, IndividualSet offspring) = 0;
    virtual ~SelectionSurvivors() = default;
};


#endif //CE_ACTIVIDAD_3_SELECTIONSURVIVORS_H
