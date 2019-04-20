//
// Created by alber on 20/04/2019.
//

#ifndef CE_ACTIVIDAD_3_DATASET_H

#include <vector>
#include "../individual/Individual.h"
#include "../individual/IndividualSet.h"

#define CE_ACTIVIDAD_3_DATASET_H


class DataSet {
private:
    std::vector<int>* times;
    std::vector<int>* generations;
    std::vector<int>* evaluations;
    std::vector<int>* hits;
    std::vector<IndividualSet*>* populations;
public:
    DataSet();
    ~DataSet();
    void addTime(int time);
    void addPopulation(IndividualSet* population);
    int getTime(int i);
    IndividualSet* getPopulation(int i);
    std::vector<IndividualSet*>* getPopulations();
    int getAverageTimeSeconds();
    double getAverageFitness();
    Individual* getBestIndividual();
    Individual* getWorstIndividual();


};


#endif //CE_ACTIVIDAD_3_DATASET_H
