//
// Created by alber on 21/04/2019.
//

#ifndef CE_ACTIVIDAD_3_DATA_H

#include <vector>
#include "../individual/IndividualSet.h"

#define CE_ACTIVIDAD_3_DATA_H


class Data {
private:
    IndividualSet* population;
    int time;
    int generations;
    int evaluations;
    int hits;
public:
    Data();
    ~Data();

    void setPopulation(IndividualSet* vector);
    void setTime(int value);
    void setGenerations(int value);
    void setEvaluations(int value);
    void setHits(int value);

    IndividualSet* getPopulation();
    int getTime();
    int getGenerations();
    int getEvaluations();
    int getHits();

    std::string toString();
};


#endif //CE_ACTIVIDAD_3_DATA_H
