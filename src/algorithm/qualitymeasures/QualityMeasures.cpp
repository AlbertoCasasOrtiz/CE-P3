//
// Created by alber on 22/04/2019.
//

#include "QualityMeasures.h"
#include <cmath>

int QualityMeasures::numHits(std::vector<double>* expected, std::vector<double>* obtained) {
    int numHits = 0;
    for(int i = 0; i < expected->size(); i++){
        if(std::abs(obtained->at(i) - expected->at(i)) < 0.1){
            numHits++;
        }
    }
    delete expected;
    delete obtained;
    return numHits;
}

double QualityMeasures::averageNumHits(DataSet dataset) {
    double averageNumHits = 0.0;
    for(int i = 0; i < dataset.getDataSet()->size(); i++){
        averageNumHits += dataset.getData(i)->getHits();
    }
    return averageNumHits / dataset.getDataSet()->size();
}

double QualityMeasures::bestFitness(IndividualSet individualSet) {
    return individualSet.getBestIndividual()->getFitness();
}

double QualityMeasures::averageBestFitness(DataSet dataSet) {
    double averageBestFitness = 0.0;
    for(int i = 0; i < dataSet.getDataSet()->size(); i++){
        averageBestFitness += dataSet.getData(i)->getPopulation()->getBestIndividual()->getFitness();
    }
    return averageBestFitness / dataSet.getDataSet()->size();
}

double QualityMeasures::worstFitness(IndividualSet individualSet) {
    return individualSet.getWorstIndividual()->getFitness();
}

double QualityMeasures::averageWorstFitness(DataSet dataSet) {
    double averageWorstFitness = 0.0;
    for(int i = 0; i < dataSet.getDataSet()->size(); i++){
        averageWorstFitness += dataSet.getData(i)->getPopulation()->getWorstIndividual()->getFitness();
    }
    return averageWorstFitness / dataSet.getDataSet()->size();
}

int QualityMeasures::numEvaluations(Data data) {
    return data.getEvaluations();
}

double QualityMeasures::averageNumEvaluations(DataSet dataSet) {
    double averageNumEvaluations = 0.0;
    for(int i = 0; i < dataSet.getDataSet()->size(); i++){
        averageNumEvaluations += dataSet.getData(i)->getEvaluations();
    }
    return averageNumEvaluations / dataSet.getDataSet()->size();
}

int QualityMeasures::time(Data data) {
    return data.getTime();
}

double QualityMeasures::averageTime(DataSet dataSet) {
    double averageTime = 0.0;
    for(int i = 0; i < dataSet.getDataSet()->size(); i++){
        averageTime += dataSet.getData(i)->getTime();
    }
    return averageTime / dataSet.getDataSet()->size();
}

