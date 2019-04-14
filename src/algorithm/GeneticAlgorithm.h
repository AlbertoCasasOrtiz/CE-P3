//
// Created by alber on 13/04/2019.
//

#ifndef CE_ACTIVIDAD_3_GENETICALGORITHM_H
    #include "individual/IndividualSet.h"
    #include "../util/Observable.h"
#define CE_ACTIVIDAD_3_GENETICALGORITHM_H




class GeneticAlgorithm: public Observable{
private:
    IndividualSet population;
    int numGenerations;
    IndividualSet elite;
    int currentGenerations;

public:
    GeneticAlgorithm();
    void execute();

    void selectElite();
    void addElite();

    void showProgress();


};


#endif //CE_ACTIVIDAD_3_GENETICALGORITHM_H
