//
// Created by Alberto Casas Ortiz.
//

#ifndef SELECTIONPARENTS_H

    #include "../../individual/IndividualSet.h"

#define SELECTIONPARENTS_H


/**
 * Class defining a selection parents method.
 */
class SelectionParents {
public:
    /**
     * Select parents from population.
     * @param population Population.
     * @return Selected parents.
     */
    virtual IndividualSet *select(IndividualSet *population) = 0;
};


#endif //SELECTIONPARENTS_H
