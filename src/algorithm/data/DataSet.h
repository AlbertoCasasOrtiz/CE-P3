//
// Created by alber on 20/04/2019.
//

#ifndef CE_ACTIVIDAD_3_DATASET_H

#include <vector>
#include "../individual/Individual.h"
#include "../individual/IndividualSet.h"
#include "Data.h"

#define CE_ACTIVIDAD_3_DATASET_H


class DataSet {
private:
    std::vector<Data*>* dataSet;
public:
    DataSet();
    ~DataSet();

    void setDataSet(std::vector<Data*>* vector);
    std::vector<Data*>* getDataSet();

    void addData(Data* data);
    Data* getData(int data);

};


#endif //CE_ACTIVIDAD_3_DATASET_H
