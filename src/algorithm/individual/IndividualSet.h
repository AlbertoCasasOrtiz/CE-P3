//
// Created by Alberto Casas Ortiz.
//

#ifndef INDIVIDUALSET_H

    #include <vector>
    #include "Individual.h"

#define INDIVIDUALSET_H


/**
 * Class containing a set of individuals.
 */
class IndividualSet{
private:
    /** Set of individuals. */
    std::vector<Individual*>* set;
    /** Average fitness of the individuals in the set. */
    double averageFitness;
    /** Best individual in the set. */
    Individual *bestIndividual;
    /** Worst individual in the set. */
    Individual *worstIndividual;

    /**
     * Comparator for sorting the individuals in descendant order by fitness.
     * @param i1 Individual to compare.
     * @param i2 Individual to compare.
     * @return Boolean indicating which individual is greater than another.
     */
    static bool comparatorDescendant(Individual* i1, Individual* i2);

    /**
     * Comparator for sorting the individuals in ascendant order by fitness.
     * @param i1 Individual to compare.
     * @param i2 Individual to compare.
     * @return Boolean indicating which individual is greater than another.
     */
    static bool comparatorAscendant(Individual* i1, Individual* i2);

public:
    /**
     * Constructor for the class IndividualSet.
     */
    IndividualSet();

    /**
     * Constructor for the class IndividualSet.
     * @param set Set of Individuals to initialize this set.
     */
    explicit IndividualSet(std::vector<Individual*>* set);

    /**
     * Destructor for the class IndividualSet.
     */
    ~IndividualSet();

    /**
     * Initialize Individuals in this set.
     */
    void initialize();

    /**
     * Evaluate Individuals in this set.
     * @param count Set to true if this evaluations enter in the count of evaluations.
     */
    void evaluate(bool count);

    /**
     * Increase age of the individuals in this set.
     */
    void increaseAge();

    /**
     * Recalculate best individual, worst individual and average fitness in this set.
     */
    void consistency();

    /**
     * Copy the full set of individuals.
     * @return A copied set of individuals. (Deep copy).
     */
    IndividualSet* copy();

    /**
     * Get number of Individuals in the set.
     * @return Number of individuals in the set.
     */
    int sizeOf();

    /**
     * Sort the individuals in the set by fitness.
     * @param ascendent Ascendent order or not.
     */
    void sort(bool ascendent);

    /**
     * Clear the full set.
     */
    void clear();

    /**
     * Add an individual to the set.
     * @param ind Individual to add.
     */
    void addElement(Individual* ind);

    /**
     * Add individuals to the set stored in a vector.
     * @param set1 std::vector containing the individuals.
     */
    void addElements(std::vector<Individual*>* set1);

    /**
     * Add individuals to the set stored in another IndividualSet.
     * @param set1 IndividualSet containing the individuals.
     */
    void addElements(IndividualSet *set1);

    /**
     * Get the vector containing Individuals.
     * @return std::vector containing individuals.
     */
    std::vector<Individual*>* getSet();

    /**
     * Get average fitness of the set.
     * @return Average fitness of the set.
     */
    double getAverageFitness();

    /**
     * Get best individual of the set.
     * @return Best individual of the set.
     */
    Individual* getBestIndividual();

    /**
     * Get worst individual of the set.
     * @return Worst individual of the set.
     */
    Individual* getWorstIndividual();

    /**
     * Get an individual of the set in the position i.
     * @param i Position of the individual.
     * @return Individual in the position i.
     */
    Individual* getIndividual(int i);

};


#endif //INDIVIDUALSET_H
