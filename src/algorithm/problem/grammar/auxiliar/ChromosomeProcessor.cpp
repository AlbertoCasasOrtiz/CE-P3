#include <utility>

//
// Created by alber on 18/04/2019.
//

#include "ChromosomeProcessor.h"
#include "../../../configuration/Configuration.h"

ChromosomeProcessor::ChromosomeProcessor(std::vector<int>* array) {
    this->chromosome = array;
    this->position = 0;
    this->consumed = 0;
    this->currentWrap = 0;
}

int ChromosomeProcessor::getInteger() {
    return this->chromosome->at(this->position);
}

void ChromosomeProcessor::consumeCodon() {
    this->consumed++;
    if(this->position + 1 == this->chromosome->size()){
        this->position = 0;
        this->currentWrap++;
    }else {
        this->position++;
    }
}

bool ChromosomeProcessor::endByWrap() {
    return this->currentWrap == Configuration::wrapping;
}

ChromosomeProcessor::~ChromosomeProcessor() {
    delete(chromosome);
}


