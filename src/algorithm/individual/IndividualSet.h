//
// Created by alber on 14/04/2019.
//

#ifndef CE_ACTIVIDAD_3_INDIVIDUALSET_H
    #include <vector>
    #include "Individual.h"

#define CE_ACTIVIDAD_3_INDIVIDUALSET_H


class IndividualSet{
protected:
    std::vector<Individual> set;
    double averageFitness;
    Individual bestIndividual;
    Individual worstIndividual;
public:
    IndividualSet();
    IndividualSet(std::vector<Individual> set);

    void initialize();
    void evaluate();
    void increaseAge();

    int sizeOf();
    void sort(bool ascendent);
    void clear();

    void addElements(std::vector<Individual> set);
    void addElements(IndividualSet set);
    std::vector<Individual> getSet();
    double getAverageFitness();
    Individual getBestIndividual();
    Individual getWorstIndividual();
    Individual getIndividual(int i);

    std::string toString();

};


#endif //CE_ACTIVIDAD_3_INDIVIDUALSET_H
