//
// Created by Alberto Casas Ortiz.
//

#include "DataSet.h"

DataSet::DataSet() {
    this->dataSet = new std::vector<ExecutionData*>();
}

DataSet::~DataSet() {
    for(auto & data : *this->dataSet)
        delete data;
    delete this->dataSet;
}


std::vector<ExecutionData*> *DataSet::getDataSet() {
    return this->dataSet;
}

void DataSet::addData(ExecutionData *executionData) {
    this->dataSet->push_back(executionData);
}

ExecutionData *DataSet::getExecutionData(int pos) {
    return this->dataSet->at(pos);
}

