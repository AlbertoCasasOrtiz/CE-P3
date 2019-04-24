//
// Created by Alberto Casas Ortiz.
//

#ifndef GENETICALGORITHM_H

    #include "individual/IndividualSet.h"
    #include "../util/timer/Timer.h"
    #include "data/DataSet.h"

#define GENETICALGORITHM_H


/**
 * Class defining a genetic algorithm.
 */
class GeneticAlgorithm{
private:
    /** Population of the algorithm. */
    IndividualSet *population;
    /** Elite of the algorithm. */
    IndividualSet *elite;
    /** Current generations of the execution. */
    static int currentGenerations;
    /** Timer of the algorithm. */
    Timer* timer;
    /** DataSet to store information of the executions. */
    DataSet* dataSet;
public:
    /** Number of evaluations in the algorithm. */
    static int evaluations;

    /**
     * Constructor for class GeneticAlgorithm.
     */
    GeneticAlgorithm();

    /**
     * Destructor for class GeneticAlgorithm.
     */
    ~GeneticAlgorithm();

    /**
     * Function which executes the algorithm.
     */
    void execute();

    /**
     * Select elite from population.
     * @return Elite selected inside a set of individuals.
     */
    IndividualSet* selectElite();

    /**
     * Add elite to population.
     */
    void addEliteToPopulation();

};


#endif //GENETICALGORITHM_H
