//
// Created by Alberto Casas Ortiz.
//

#ifndef QUALITYMEASURES_H

    #include <vector>
    #include "../data/DataSet.h"

#define QUALITYMEASURES_H


/**
 * Get quality measures of the algorithm.
 */
class QualityMeasures {
public:
    /**
     * Get number of hits achieved by the solution.
     * @param expected Expected solution.
     * @param obtained Obtained solution.
     * @return Number of hits achieved.
     */
    static int numHits(std::vector<double>* expected, std::vector<double>* obtained);

    /**
     * Get best fitness achieved by a population.
     * @param individualSet Set containing the best individual.
     * @return Best fitness achieved in a population
     */
    static double bestFitness(IndividualSet individualSet);

    /**
     * Get worst fitness achieved by a population.
     * @param individualSet Set containing the worst individual.
     * @return Worst fitness achieved in a population
     */
    static double worstFitness(IndividualSet individualSet);

    /**
     * Get number of evaluations completed by an execution.
     * @param data Information of the execution.
     * @return Number of evaluations completed by an execution.
     */
    static int numEvaluations(ExecutionData data);

    /**
     * Get time elapsed in an execution.
     * @param data Information of the execution.
     * @return Time elapsed in an execution.
     */
    static double time(ExecutionData data);


    /**
     * Get average number of hits achieved by a set of executions.
     * @param dataset DataSet containing data of executions.
     * @return Average number of hits.
     */
    static double averageNumHits(DataSet dataset);

    /**
     * Get average best fitness achieved by a set of executions.
     * @param dataset DataSet containing data of executions.
     * @return Average best fitness.
     */
    static double averageBestFitness(DataSet dataSet);

    /**
     * Get average worst fitness achieved by a set of executions.
     * @param dataset DataSet containing data of executions.
     * @return Average worst fitness.
     */
    static double averageWorstFitness(DataSet dataSet);

    /**
     * Get average number of evaluations completed by a set of executions.
     * @param dataset DataSet containing data of executions.
     * @return Average number of evaluations fitness.
     */
    static double averageNumEvaluations(DataSet dataSet);

    /**
     * Get average time elapsed in a set of executions.
     * @param dataset DataSet containing data of executions.
     * @return Average time.
     */
    static double averageTime(DataSet dataSet);
};


#endif //QUALITYMEASURES_H
