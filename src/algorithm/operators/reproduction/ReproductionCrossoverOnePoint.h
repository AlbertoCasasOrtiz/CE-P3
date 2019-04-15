//
// Created by alber on 15/04/2019.
//

#ifndef CE_ACTIVIDAD_3_REPRODUCTIONCROSSOVERONEPOINT_H
#define CE_ACTIVIDAD_3_REPRODUCTIONCROSSOVERONEPOINT_H


#include "Reproduction.h"

class ReproductionCrossoverOnePoint: public Reproduction{
public:
    IndividualSet reproduce(IndividualSet parents) override;
    IndividualSet crossover(Individual i1, Individual i2);
    Individual createIndividual(Individual i1, Individual i2, int point1, int point2);
};


#endif //CE_ACTIVIDAD_3_REPRODUCTIONCROSSOVERONEPOINT_H
