//
// Created by Alberto Casas Ortiz.
//

#ifndef REPRODUCTION_H

    #include "../../individual/IndividualSet.h"

#define REPRODUCTION_H


/**
 * Class defining a reproduction method.
 */
class Reproduction {
public:
    /**
     * Reproduce a full set of parents.
     * @param parents Parents to reproduce.
     * @return Offspring of the set of parents.
     */
    virtual IndividualSet *reproduce(IndividualSet *parents) = 0;
};


#endif //REPRODUCTION_H
