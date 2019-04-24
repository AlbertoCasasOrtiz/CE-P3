//
// Created by Alberto Casas Ortiz.
//

#ifndef SELECTIONSURVIVORSGENERATIONAL_H

    #include "../../individual/IndividualSet.h"
    #include "SelectionSurvivors.h"

#define SELECTIONSURVIVORSGENERATIONAL_H


/**
 * Select survivors from offspring. Select the best of the offspring.
 */
class SelectionSurvivorsGenerational: public SelectionSurvivors{
public:
    /**
     * Select survivors from the offspring.
     * @param parents Selected parents.
     * @param offspring Generated offspring.
     * @return Survivors selected.
     */
    IndividualSet *select(IndividualSet *parents, IndividualSet *offspring) override;
};


#endif //SELECTIONSURVIVORSGENERATIONAL_H
