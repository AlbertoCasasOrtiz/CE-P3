//
// Created by Alberto Casas Ortiz.
//

#ifndef MUTATION_H

    #include "../../individual/IndividualSet.h"

#define MUTATION_H


/**
 * Class defining a mutation method.
 */
class Mutation {
public:
    /**
     * Mutate a set of individuals.
     * @param set Set of individuals.
     */
    virtual void mutate(IndividualSet *set) = 0;
};


#endif //MUTATION_H
