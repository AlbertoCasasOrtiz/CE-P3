//
// Created by Alberto Casas Ortiz.
//

#include "SelectionSurvivorsGenerational.h"
#include "../../configuration/Configuration.h"

IndividualSet *SelectionSurvivorsGenerational::select(IndividualSet *parents, IndividualSet *offspring) {
    offspring->sort(true);
    auto *individualSet = new IndividualSet();
    for(int i = 0; i < Configuration::populationSize; i++){
        individualSet->addElement(offspring->getSet()->at(i)->copy());
    }
    return individualSet;
}
