//
// Created by Alberto Casas Ortiz.
//

#include "SelectionParentsAllParents.h"

IndividualSet *SelectionParentsAllParents::select(IndividualSet *parents) {
    auto *set = new IndividualSet();
    for(int i = 0; i < parents->sizeOf(); i++){
        set->addElement(parents->getSet()->at(i)->copy());
    }
    return set;
}
