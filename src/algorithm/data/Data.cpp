//
// Created by alber on 21/04/2019.
//

#include "Data.h"
#include "../individual/IndividualSet.h"

Data::Data() {
    this->population = new IndividualSet();
    this->time = 0;
    this->generations = 0;
    this->evaluations = 0;
    this->hits = 0;
}

Data::~Data(){
    delete this->population;
}

void Data::setPopulation(IndividualSet *vector) {
    this->population = vector;
}

void Data::setTime(int value) {
    this->time = value;
}

void Data::setGenerations(int value) {
    this->generations = value;
}

void Data::setEvaluations(int value) {
    this->evaluations = value;
}

void Data::setHits(int value) {
    this->hits = value;
}

IndividualSet *Data::getPopulation() {
    return this->population;
}

int Data::getTime() {
    return this->time;
}

int Data::getGenerations() {
    return this->generations;
}

int Data::getEvaluations() {
    return this->evaluations;
}

int Data::getHits() {
    return this->hits;
}




