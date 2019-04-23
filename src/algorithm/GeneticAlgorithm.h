//
// Created by alber on 13/04/2019.
//

#ifndef CE_ACTIVIDAD_3_GENETICALGORITHM_H
    #include "individual/IndividualSet.h"
#include "../util/timer/Timer.h"
#include "data/DataSet.h"

#define CE_ACTIVIDAD_3_GENETICALGORITHM_H




class GeneticAlgorithm{
private:
    IndividualSet *population;
    IndividualSet *elite;
    static int currentGenerations;
    Timer* timer;
    DataSet* dataSet;
public:
    static int evaluations;
    GeneticAlgorithm();
    ~GeneticAlgorithm();
    void execute();

    IndividualSet* selectElite();
    void addEliteToPopulation();

};


#endif //CE_ACTIVIDAD_3_GENETICALGORITHM_H
