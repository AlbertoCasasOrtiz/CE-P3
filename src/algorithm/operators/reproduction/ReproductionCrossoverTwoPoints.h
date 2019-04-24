//
// Created by Alberto Casas Ortiz.
//

#ifndef REPRODUCTIONCROSSOVERTWOPOINTS_H

    #include "../../individual/IndividualSet.h"
    #include "Reproduction.h"

#define REPRODUCTIONCROSSOVERTWOPOINTS_H


/**
 * Two Points Crossover method. Generate two child from the parents making a crossover in two points.
 */
class ReproductionCrossoverTwoPoints: public Reproduction{
public:
    /**
     * Reproduce a full set of parents.
     * @param parents Parents to reproduce.
     * @return Offspring of the set of parents.
     */
    IndividualSet *reproduce(IndividualSet *parents) override;

    /**
     * Make crossover between two individuals.
     * @param i1 Individual which will reproduce.
     * @param i2 Individual which will reproduce.
     * @return Offspring of the individuals.
     */
    IndividualSet *crossover(Individual* i1, Individual* i2);

    /**
     * Create offspring of two individuals.
     * @param i1 Individual which will reproduce.
     * @param i2 Individual which will reproduce.
     * @param point1 Crossover point of i1.
     * @param point2 Crossove point of i2.
     * @return Child of the individual in those points.
     */
    Individual* createIndividual(Individual* i1, Individual* i2, int point1, int point2);
};


#endif //REPRODUCTIONCROSSOVERTWOPOINTS_H
