//
// Created by alber on 14/04/2019.
//

#ifndef CE_ACTIVIDAD_3_INDIVIDUAL_H
#include <vector>
#include <string>
#define CE_ACTIVIDAD_3_INDIVIDUAL_H


class Individual {
private:
    std::vector<int> params;
    double fitness;
    double probability;
    double accumulatedProbability;
    int age;
public:
    Individual();

    void initialize();
    void evaluate();
    std::vector<double> getFenotype();

    int sizeOf();

    int getAge();
    void increaseAge();
    std::vector<int> getParam();
    void addParam(int object);
    double getProbability();
    void setProbability(double probability);
    double getAccumulatedProbability();
    void setAccumulatedProbability(double accumulatedProbability);
    void setProbabilities(double probability, double accumulatedProbability);
    double getFitness();
    void setFitness(double fitness);

    Individual* copy();
    std::string toString();
};


#endif //CE_ACTIVIDAD_3_INDIVIDUAL_H
