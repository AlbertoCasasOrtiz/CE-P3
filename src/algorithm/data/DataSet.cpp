//
// Created by alber on 20/04/2019.
//

#include "DataSet.h"

DataSet::DataSet() {
    this->dataSet = new std::vector<Data*>();
}

DataSet::~DataSet() {
    for(auto & data : *this->dataSet)
        delete data;
    delete this->dataSet;
}

void DataSet::setDataSet(std::vector<Data *> *vector) {
    this->dataSet = vector;
}

std::vector<Data*> *DataSet::getDataSet() {
    return this->dataSet;
}

void DataSet::addData(Data *data) {
    this->dataSet->push_back(data);
}

Data *DataSet::getData(int data) {
    return this->dataSet->at(data);
}

