//
// Created by Alberto Casas Ortiz.
//

#ifndef MUTATIONSWITCH_H

    #include "Mutation.h"

#define MUTATIONSWITCH_H


/**
 * MutationSwitch method. Switch the value of the codon to other valid random value.
 */
class MutationSwitch: public Mutation {
public:
    /**
     * Mutate a set of individuals.
     * @param set Set of individuals.
     */
    void mutate(IndividualSet *set) override;

    /**
     * Mutate an Individual.
     * @param ind Individual to be mutated.
     */
    void mutateIndividual(Individual* ind);
};


#endif //MUTATIONSWITCH_H
