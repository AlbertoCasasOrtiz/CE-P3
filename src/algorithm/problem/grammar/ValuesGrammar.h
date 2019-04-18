//
// Created by alber on 18/04/2019.
//

#ifndef CE_ACTIVIDAD_3_VALUESGRAMMAR_H
#define CE_ACTIVIDAD_3_VALUESGRAMMAR_H


#include "auxiliar/ChromosomeProcessor.h"

class ValuesGrammar {
public:
    ChromosomeProcessor chromosomeProcessor;
    std::vector<double> getValues();
    ValuesGrammar(std::vector<int> chromosome);
private:
    std::vector<double> expr();
    std::vector<double> kg();
    std::vector<double> kp();
    std::vector<double> ks();
    double sign();
    double real();
    void null();
    int degree();
    int oneNine();
    int zeroNine();
};


#endif //CE_ACTIVIDAD_3_VALUESGRAMMAR_H
