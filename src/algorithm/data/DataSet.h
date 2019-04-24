//
// Created by Alberto Casas Ortiz.
//

#ifndef DATASET_H

    #include <vector>
    #include "../individual/Individual.h"
    #include "../individual/IndividualSet.h"
    #include "ExecutionData.h"

#define DATASET_H


/**
 * Class containing data gathered in a set of executions.
 */
class DataSet {
private:
    /** DataSet containing data gathered in a set of executions. */
    std::vector<ExecutionData*>* dataSet;
public:
    /**
     * Constructor for class DataSet.
     */
    DataSet();

    /**
     * Destructor for class DataSet.
     */
    ~DataSet();

    /**
     * Get the full DataSet.
     * @return Full DataSet.
     */
    std::vector<ExecutionData*>* getDataSet();

    /**
     * Add an execution to the dataSet.
     * @param executionData Execution to add to the dataSet.
     */
    void addData(ExecutionData* executionData);

    /**
     * Get data of an execution in the position pos.
     * @param pos Position of the execution.
     * @return Execution in position pos.
     */
    ExecutionData* getExecutionData(int pos);

};


#endif //DATASET_H
