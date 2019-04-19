//
// Created by alber on 14/04/2019.
//

#ifndef CE_ACTIVIDAD_3_CONFIGURATION_H

#include <string>
#include "../operators/mutation/Mutation.h"
#include "../operators/reproduction/Reproduction.h"
#include "../operators/selectionsurvivors/SelectionSurvivors.h"
#include "../operators/selectionparents/SelectionParents.h"
#include "../problem/Problem.h"

#define CE_ACTIVIDAD_3_CONFIGURATION_H

class Configuration {
public:
    static Problem* problem;
    static int numExecutions;
    static int populationSize;
    static int offspringSize;
    static int maxNumGenerations;
    static int maxCodonValue;
    static int wrapping;
    static int minInterval;
    static int maxInterval;
    static int samples;
    static int function;
    static std::vector<double>* x;
    static int maxChromosomeSize;
    static SelectionParents* selectionParents;
    static Reproduction* reproduction;
    static double pRep;
    static Mutation* mutation;
    static double pMut;
    static SelectionSurvivors* selectionSurvivors;
    static bool elitism;
    static int numElitism;
    static void loadConfiguration();
    static void parseLine(const std::string& line, int nLine);
    static void generateX();
};


#endif //CE_ACTIVIDAD_3_CONFIGURATION_H
