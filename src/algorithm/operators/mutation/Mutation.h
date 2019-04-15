//
// Created by alber on 15/04/2019.
//

#ifndef CE_ACTIVIDAD_3_MUTATION_H
#define CE_ACTIVIDAD_3_MUTATION_H


#include "../../individual/IndividualSet.h"

class Mutation {
public:
    virtual IndividualSet mutate(IndividualSet set);
};


#endif //CE_ACTIVIDAD_3_MUTATION_H
