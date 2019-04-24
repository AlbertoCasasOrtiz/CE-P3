//
// Created by Alberto Casas Ortiz.
//

#include <iostream>
#include "VectorFunctions.h"

std::vector<double>* VectorFunctions::add(std::vector<double>* vector1, std::vector<double>* vector2) {
    auto* res = new std::vector<double>();
    for(unsigned int i = 0; i < vector1->size(); i++){
        res->push_back(vector1->at(i) + vector2->at(i));
    }
    delete vector1;
    delete vector2;
    return res;
}

std::vector<double>* VectorFunctions::add(std::vector<double>* vector1, double d1) {
    auto* res = new std::vector<double>();
    res->reserve(vector1->size());
    for(double i : *vector1){
        res->push_back(i + d1);
    }
    delete vector1;
    return res;
}

std::vector<double>* VectorFunctions::mul(std::vector<double>* vector1, std::vector<double>* vector2) {

    auto* res = new std::vector<double>();
    for(unsigned int i = 0; i < vector1->size(); i++){
        res->push_back(vector1->at(i) * vector2->at(i));
    }
    delete vector1;
    delete vector2;
    return res;
}

std::vector<double>* VectorFunctions::mul(std::vector<double>* vector1, double d1) {
    auto* res = new std::vector<double>();
    res->reserve(vector1->size());
    for(double i : *vector1){
        res->push_back(i * d1);
    }
    delete vector1;
    return res;
}
