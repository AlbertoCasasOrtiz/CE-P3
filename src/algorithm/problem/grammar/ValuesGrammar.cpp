//
// Created by alber on 18/04/2019.
//

#include "ValuesGrammar.h"
#include "../../configuration/Configuration.h"
#include "auxiliar/VectorFunctions.h"
#include <cmath>
#include <limits>

ValuesGrammar::ValuesGrammar(std::vector<int> chromosome) {
    this->chromosomeProcessor = ChromosomeProcessor(chromosome);
}

std::vector<double> ValuesGrammar::getValues() {
    std::vector<double> res = this->expr();
    return this->chromosomeProcessor.endByWrap() ? std::vector<double>() : res;
}

std::vector<double> ValuesGrammar::expr() {
    if(this->chromosomeProcessor.endByWrap()) return std::vector<double>();
    this->chromosomeProcessor.consumeCodon();
    switch (this->chromosomeProcessor.getInteger() % 6){
        case 0:
            return VectorFunctions::mul(this->kg(), this->sign()*this->real());
        case 1:
            return VectorFunctions::mul(VectorFunctions::mul(this->kg(), this->sign()*this->real()), this->expr());
        case 2:
            return VectorFunctions::mul(this->kp(), this->sign()*this->real());
        case 3:
            return VectorFunctions::mul(VectorFunctions::mul(this->kp(), this->sign()*this->real()), this->expr());
        case 4:
            return VectorFunctions::mul(this->ks(), this->sign()*this->real());
        case 5:
            return VectorFunctions::mul(VectorFunctions::mul(this->ks(), this->sign()*this->real()), this->expr());
        default:
            return std::vector<double>();
    }
}

std::vector<double> ValuesGrammar::kg() {
    if(this->chromosomeProcessor.endByWrap()) return std::vector<double>();
    std::vector<double> res;
    double d1 = this->real();
    double d2 = this->real();
    int g = this->degree();
    for(double x : Configuration::x){
        res.push_back(exp(-(d1*pow(d2-x, 2))));
    }
    return res;
}

std::vector<double> ValuesGrammar::kp() {
    if(this->chromosomeProcessor.endByWrap()) return std::vector<double>();
    std::vector<double> res;
    double d1 = this->real();
    double d2 = this->real();
    int g = this->degree();
    for(double x : Configuration::x){
        res.push_back(pow(d1*x+d2, g));
    }
    return res;
}

std::vector<double> ValuesGrammar::ks() {
    if(this->chromosomeProcessor.endByWrap()) return std::vector<double>();
    std::vector<double> res;
    double d1 = this->real();
    double d2 = this->real();
    this->null();
    for(double x : Configuration::x){
        res.push_back(tanh(d1*x+d2));
    }
    return res;
}

double ValuesGrammar::sign() {
    if(this->chromosomeProcessor.endByWrap()) return std::numeric_limits<double>::min();
    this->chromosomeProcessor.consumeCodon();
    switch (this->chromosomeProcessor.getInteger() % 2){
        case 0:
            return 1.0;
        case 1:
            return -1.0;
    }
    //TODO Error
    return std::numeric_limits<double>::min();
}

double ValuesGrammar::real() {
    if(this->chromosomeProcessor.endByWrap()) return std::numeric_limits<double>::min();
    double d = this->oneNine() + this->zeroNine()*0.1;
    double exp = pow(1, this->sign()*this->zeroNine());
    return d*exp;
}

void ValuesGrammar::null() {
    if(this->chromosomeProcessor.endByWrap()) return;
    this->chromosomeProcessor.consumeCodon();
}

int ValuesGrammar::degree() {
    if(this->chromosomeProcessor.endByWrap()) return std::numeric_limits<int>::min();
    this->chromosomeProcessor.consumeCodon();
    return this->chromosomeProcessor.getInteger() % 5;
}

int ValuesGrammar::oneNine() {
    if(this->chromosomeProcessor.endByWrap()) return std::numeric_limits<int>::min();
    this->chromosomeProcessor.consumeCodon();
    return (this->chromosomeProcessor.getInteger() % 9) + 1;
}

int ValuesGrammar::zeroNine() {
    if(this->chromosomeProcessor.endByWrap()) return std::numeric_limits<int>::min();
    this->chromosomeProcessor.consumeCodon();
    return this->chromosomeProcessor.getInteger() % 10;
}
