//
// Created by alber on 15/04/2019.
//

#ifndef CE_ACTIVIDAD_3_MUTATIONSWITCH_H
#define CE_ACTIVIDAD_3_MUTATIONSWITCH_H


#include "Mutation.h"

class MutationSwitch: public Mutation {
public:
    IndividualSet *mutate(IndividualSet *set) override;
    void mutateIndividual(Individual* ind);
};


#endif //CE_ACTIVIDAD_3_MUTATIONSWITCH_H
