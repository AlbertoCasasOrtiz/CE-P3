//
// Created by Alberto Casas Ortiz.
//

#ifndef DATA_H

    #include <vector>
    #include "../individual/IndividualSet.h"

#define DATA_H


/**
 * Class containing data gathered in an execution.
 */
class ExecutionData {
private:
    /** Population of the execution. */
    IndividualSet* population{};
    /** Time elapsed during the execution. */
    double time;
    /** Number of generations completed in the execution. */
    int generations;
    /** Number of evaluations done in the execution. */
    int evaluations;
    /** Number of hits achieved in the solution of the execution. */
    int hits;
    /** Success rate in the execution. */
    double successRate;
    /** Name of the execution. */
    std::string name;
public:
    /**
     * Constructor for class Data.
     */
    ExecutionData();

    /**
     * Destructor for class Data.
     */
    ~ExecutionData();

    /**
     * Set the population in the last generation of the execution.
     * @param vector IndividualSet which contains the population in the last generation of the execution.
     */
    void setPopulation(IndividualSet* vector);

    /**
     * Set time elapsed during the execution.
     * @param value Time elapsed during the execution in seconds.
     */
    void setTime(double value);

    /**
     * Set number of generations completed in the execution.
     * @param value Number of generations completed in the execution.
     */
    void setGenerations(int value);

    /**
     * Set number of evaluations done in the execution.
     * @param value Number of evaluations done in the execution.
     */
    void setEvaluations(int value);

    /**
     * Set number of hits achieved in the solution of the execution.
     * @param value Number of hits achieved in the solution of th execution.
     */
    void setHits(int value);

    /**
     * Set sucess ratoe of the solution of the execution.
     * @param value
     */
    void setSuccessRate(double value);

    /**
     * Set the name of the execution.
     * @param name Name of the execution.
     */
    void setName(std::string value);

    /**
     * Get population in the last generation of the execution.
     * @return IndividualSet containing population in the last generation of the execution.
     */
    IndividualSet* getPopulation();

    /**
     * Get time elapsed during the execution.
     * @return Time elapsed during the execution.
     */
    double getTime();

    /**
     * Get number of generations completed during the execution.
     * @return Number of generations completed during the execution.
     */
    int getGenerations();

    /**
     * Get number of evaluations done during the execution.
     * @return Number of evaluations done during the execution.
     */
    int getEvaluations();

    /**
     * Get number of hits achieved during the execution.
     * @return Number of hits achieved during the execution.
     */
    int getHits();

    /**
     * Get success rate of the best solution of the algorithm.
     * @return Success rate of the best solution of the algorithm.
     */
    double getSuccessRate();

    /**
     * Get name of the execution.
     * @return Name of the execution.
     */
    std::string getName();

    /**
     * Get representation of the execution as string,
     * @return Representation of the execution as string.
     */
    std::string toString();
};


#endif //DATA_H
