//
// Created by Alberto Casas Ortiz.
//

#include "QualityMeasures.h"
#include "../problem/functions/Functions.h"
#include "../configuration/Configuration.h"
#include <cmath>

int QualityMeasures::numHits(ExecutionData* data) {
    std::vector<double>* expected = Functions::executeFunction(Configuration::function);
    std::vector<double>* obtained = data->getPopulation()->getBestIndividual()->getFenotype();
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

double QualityMeasures::successRate(ExecutionData *data) {
    return (data->getHits()*100.0)/Configuration::samples;
}

double QualityMeasures::bestFitness(ExecutionData* data) {
    return data->getPopulation()->getBestIndividual()->getFitness();
}

double QualityMeasures::worstFitness(ExecutionData* data) {
    return data->getPopulation()->getWorstIndividual()->getFitness();
}

int QualityMeasures::numEvaluations(ExecutionData* data) {
    return data->getEvaluations();
}

double QualityMeasures::time(ExecutionData* data) {
    return data->getTime();
}

double QualityMeasures::averageNumHits(DataSet* dataset) {
    double averageNumHits = 0.0;
    for(int i = 0; i < dataset->getDataSet()->size(); i++){
        averageNumHits += dataset->getExecutionData(i)->getHits();
    }
    return averageNumHits / dataset->getDataSet()->size();
}

double QualityMeasures::averageBestFitness(DataSet* dataSet) {
    double averageBestFitness = 0.0;
    for(int i = 0; i < dataSet->getDataSet()->size(); i++){
        averageBestFitness += dataSet->getExecutionData(i)->getPopulation()->getBestIndividual()->getFitness();
    }
    return averageBestFitness / dataSet->getDataSet()->size();
}

double QualityMeasures::averageWorstFitness(DataSet* dataSet) {
    double averageWorstFitness = 0.0;
    for(int i = 0; i < dataSet->getDataSet()->size(); i++){
        averageWorstFitness += dataSet->getExecutionData(i)->getPopulation()->getWorstIndividual()->getFitness();
    }
    return averageWorstFitness / dataSet->getDataSet()->size();
}

double QualityMeasures::averageNumEvaluations(DataSet* dataSet) {
    double averageNumEvaluations = 0.0;
    for(int i = 0; i < dataSet->getDataSet()->size(); i++){
        averageNumEvaluations += dataSet->getExecutionData(i)->getEvaluations();
    }
    return averageNumEvaluations / dataSet->getDataSet()->size();
}

double QualityMeasures::averageTime(DataSet* dataSet) {
    double averageTime = 0.0;
    for(int i = 0; i < dataSet->getDataSet()->size(); i++){
        averageTime += dataSet->getExecutionData(i)->getTime();
    }
    return averageTime / dataSet->getDataSet()->size();
}
