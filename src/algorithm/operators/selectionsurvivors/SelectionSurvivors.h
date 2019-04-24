//
// Created by Alberto Casas Ortiz.
//

#ifndef SELECTIONSURVIVORS_H

    #include "../../individual/IndividualSet.h"

#define SELECTIONSURVIVORS_H


/**
 * Class defining a selection survivors method.
 */
class SelectionSurvivors {
public:
    /**
     * Select survivors from parents and offspring.
     * @param parents Selected parents.
     * @param offspring Generated offspring.
     * @return Survivors selected.
     */
    virtual IndividualSet *select(IndividualSet *parents, IndividualSet *offspring) = 0;
};


#endif //SELECTIONSURVIVORS_H
