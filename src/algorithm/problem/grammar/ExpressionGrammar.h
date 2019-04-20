//
// Created by alber on 18/04/2019.
//

#ifndef CE_ACTIVIDAD_3_EXPRESSIONGRAMMAR_H
#define CE_ACTIVIDAD_3_EXPRESSIONGRAMMAR_H


#include <string>
#include "auxiliar/ChromosomeProcessor.h"

class ExpressionGrammar {
public:
    ChromosomeProcessor* chromosomeProcessor;
    std::string getExpression();
    explicit ExpressionGrammar(std::vector<int>* chromosome);
    ~ExpressionGrammar();
private:
    std::string expr();
    std::string kg();
    std::string kp();
    std::string ks();
    std::string sign();
    std::string real();
    std::string null();
    std::string degree();
    std::string oneNine();
    std::string zeroNine();
};


#endif //CE_ACTIVIDAD_3_EXPRESSIONGRAMMAR_H
