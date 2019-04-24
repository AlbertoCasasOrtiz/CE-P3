//
// Created by Alberto Casas Ortiz.
//

#ifndef SELECTIONPARENTSALLPARENTS_H

    #include "SelectionParents.h"

#define SELECTIONPARENTSALLPARENTS_H


/**
 * Select all parents from the population.
 */
class SelectionParentsAllParents: public SelectionParents{
public:
    /**
     * Select parents from population. (Deep copy).
     * @param population Population.
     * @return Selected parents.
     */
    IndividualSet *select(IndividualSet *parents) override;

};


#endif //SELECTIONPARENTSALLPARENTS_H
