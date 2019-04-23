//
// Created by alber on 22/04/2019.
//

#ifndef CE_ACTIVIDAD_3_QUALITYMEASURES_H

#include <vector>
#include "../data/DataSet.h"

#define CE_ACTIVIDAD_3_QUALITYMEASURES_H


class QualityMeasures {
public:
    static int numHits(std::vector<double>* expected, std::vector<double>* obtained);
    static double averageNumHits(DataSet dataset);
    static double bestFitness(IndividualSet individualSet);
    static double averageBestFitness(DataSet dataSet);
    static double worstFitness(IndividualSet individualSet);
    static double averageWorstFitness(DataSet dataSet);
    static int numEvaluations(Data data);
    static double averageNumEvaluations(DataSet dataSet);
    static int time(Data data);
    static double averageTime(DataSet dataSet);
};


#endif //CE_ACTIVIDAD_3_QUALITYMEASURES_H
