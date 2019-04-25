//
// Created by Alberto Casas Ortiz.
//

#ifndef WRITERESULTSINFILE_H

    #include <iostream>
    #include <fstream>
#include "../ExecutionData.h"

#define WRITERESULTSINFILE_H


class WriteResultsInFile {
public:
    static void writeResults(ExecutionData* data);
};


#endif //WRITERESULTSINFILE_H
