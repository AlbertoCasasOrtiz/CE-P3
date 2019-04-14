//
// Created by alber on 14/04/2019.
//

#ifndef CE_ACTIVIDAD_3_CONFIGURATION_H

#include <string>

#define CE_ACTIVIDAD_3_CONFIGURATION_H

class Configuration {
private:
    static std::string pathConfig;
public:
    static Problem problem;
    static int numExecutions;
    static int populationSize;
    static int offspringSize;
    static int maxNumGenerations;
    static int maxCodonValue;
    static int maxChromosomeSize;
    static SelectionParents selectionParents;
    static double s;
    static Reproduction reproduction;
    static double pRep;
    static Mutation mutation;
    static double pMut;
    static SurvivorsSelection survivorsSelection;
    static bool elitism;
    static int numElitism;
    static void loadConfiguration();
    static void parseLine(std::string line, int nLine);


public:
};


#endif //CE_ACTIVIDAD_3_CONFIGURATION_H
