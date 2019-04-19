//
// Created by alber on 17/04/2019.
//

#ifndef CE_ACTIVIDAD_3_SELECTIONPARENTS_H
#include "../../individual/IndividualSet.h"

#define CE_ACTIVIDAD_3_SELECTIONPARENTS_H


class SelectionParents {
public:
    virtual IndividualSet *select(IndividualSet *parents) = 0;
    virtual ~SelectionParents() = default;
};


#endif //CE_ACTIVIDAD_3_SELECTIONPARENTS_H
