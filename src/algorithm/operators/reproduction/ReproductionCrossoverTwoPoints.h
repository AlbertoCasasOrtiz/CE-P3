//
// Created by alber on 24/04/2019.
//

#ifndef CE_ACTIVIDAD_3_REPRODUCTIONCROSSOVERTWOPOINTS_H
#define CE_ACTIVIDAD_3_REPRODUCTIONCROSSOVERTWOPOINTS_H


#include "../../individual/IndividualSet.h"
#include "Reproduction.h"

class ReproductionCrossoverTwoPoints: public Reproduction{
public:
    IndividualSet *reproduce(IndividualSet *parents) override;
    IndividualSet *crossover(Individual* i1, Individual* i2);
    Individual* createIndividual(Individual* i1, Individual* i2, int point1, int point2);
};


#endif //CE_ACTIVIDAD_3_REPRODUCTIONCROSSOVERTWOPOINTS_H
