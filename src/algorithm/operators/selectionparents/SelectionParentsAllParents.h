//
// Created by alber on 17/04/2019.
//

#ifndef CE_ACTIVIDAD_3_SELECTIONPARENTSALLPARENTS_H
#define CE_ACTIVIDAD_3_SELECTIONPARENTSALLPARENTS_H


#include "SelectionParents.h"

class SelectionParentsAllParents: public SelectionParents{
public:
    IndividualSet select(IndividualSet parents) override;

};


#endif //CE_ACTIVIDAD_3_SELECTIONPARENTSALLPARENTS_H
