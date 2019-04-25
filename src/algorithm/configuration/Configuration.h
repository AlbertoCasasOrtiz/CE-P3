//
// Created by Alberto Casas Ortiz.
//

#ifndef CONFIGURATION_H

    #include <string>
    #include "../operators/mutation/Mutation.h"
    #include "../operators/reproduction/Reproduction.h"
    #include "../operators/selectionsurvivors/SelectionSurvivors.h"
    #include "../operators/selectionparents/SelectionParents.h"
    #include "../problem/Problem.h"

#define CONFIGURATION_H


/**
 * Class containing configuration values of the algorithm.
 */
class Configuration {
public:
    /** Name of the execution. */
    static std::string executionName;
    /** Problem to solve. */
    static Problem* problem;
    /** Name of the problem. */
    static std::string problemName;
    /** Number of executions of the algorithm. */
    static int numExecutions;
    /** Size of the population. */
    static int populationSize;
    /** Size of generated offspring. */
    static int offspringSize;
    /** Maximum number of generations executed. */
    static int maxNumGenerations;
    /** Maximum integer value that a codon can take. */
    static int maxCodonValue;
    /** Maximum wrapping value when processing a chromosome. */
    static int wrapping;
    /** Minimum value of the studied interval. */
    static int minInterval;
    /** Maximum value of the studied interval. */
    static int maxInterval;
    /** Number of samples of the studied interval. */
    static int samples;
    /** Function studied. */
    static int function;
    /** Values of x in the studied interval. */
    static std::vector<double>* x;
    /** Maximum size of a chromosome. */
    static int maxChromosomeSize;
    /** Method of parents selection used. */
    static SelectionParents* selectionParents;
    /** Name of selection parents. */
    static std::string nameSelectionParents;
    /** Method of reproduction used. */
    static Reproduction* reproduction;
    /** Name of reproduction. */
    static std::string nameReproduction;
    /** Probability of apply the reprodution method over a pair of chromosomes. */
    static double pRep;
    /** Name of mutation.*/
    static std::string nameMutation;
    /** Method of mutation used. */
    static Mutation* mutation;
    /** Probability of apply mutation method over a codon. */
    static double pMut;
    /** Name of selection survivors. */
    static std::string nameSelectionSurvivors;
    /** Mehod of survivors selection. */
    static SelectionSurvivors* selectionSurvivors;
    /** Boolean that indicates if elitism is applied. */
    static bool elitism;
    /** Number of individuals selected by elitism that passes to the next generation. */
    static int numElitism;

    /**
     * Method for load configuration.
     */
    static void loadConfiguration();

private:
    /**
     * Parse a line of the configuration file.
     * @param line Line of configuration file.
     * @param nLine Number of line of configuration file.
     */
    static void parseLine(const std::string& line, int nLine);

    /**
     * Generate values of vector x.
     */
    static void generateX();
};


#endif //CONFIGURATION_H
