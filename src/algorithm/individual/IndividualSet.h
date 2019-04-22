//
// Created by alber on 14/04/2019.
//

#ifndef CE_ACTIVIDAD_3_INDIVIDUALSET_H
    #include <vector>
    #include "Individual.h"

#define CE_ACTIVIDAD_3_INDIVIDUALSET_H


class IndividualSet{
protected:
    std::vector<Individual*>* set;
    double averageFitness;
    Individual *bestIndividual;
    Individual *worstIndividual;
public:
    IndividualSet();
    explicit IndividualSet(std::vector<Individual*>* set);
    ~IndividualSet();

    void initialize();
    void evaluate();
    void increaseAge();
    void consistency();
    IndividualSet* clone();

    int sizeOf();
    void sort(bool ascendent);
    static bool comparatorDescendant(Individual* i1, Individual* i2);
    static bool comparatorAscendant(Individual* i1, Individual* i2);
    void clear();

    void addElement(Individual* ind);
    void addElements(std::vector<Individual*>* set1);
    void addElements(IndividualSet *set1);
    std::vector<Individual*>* getSet();
    double getAverageFitness();
    Individual* getBestIndividual();
    Individual* getWorstIndividual();
    Individual* getIndividual(int i);

};


#endif //CE_ACTIVIDAD_3_INDIVIDUALSET_H
