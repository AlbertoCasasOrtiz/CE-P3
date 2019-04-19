//
// Created by alber on 13/04/2019.
//

#ifndef CE_ACTIVIDAD_3_GENETICALGORITHM_H
    #include "individual/IndividualSet.h"
    #include "../util/observerpattern/Observable.h"
#include "../util/timer/Timer.h"

#define CE_ACTIVIDAD_3_GENETICALGORITHM_H




class GeneticAlgorithm{
private:
    IndividualSet *population;
    IndividualSet *elite;
    int currentGenerations;
    Timer* timer;
public:
    GeneticAlgorithm();
    void execute();

    void selectElite();
    void addEliteToPopulation();

};


#endif //CE_ACTIVIDAD_3_GENETICALGORITHM_H
