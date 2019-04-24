#include <utility>
//
// Created by Alberto Casas Ortiz.
//

#include "ValuesGrammar.h"
#include "../../configuration/Configuration.h"
#include "auxiliar/VectorFunctions.h"
#include <cmath>
#include <limits>
#include <iostream>

ValuesGrammar::ValuesGrammar(std::vector<int>* chromosome) {
    this->chromosomeProcessor = new ChromosomeProcessor(chromosome);
}

std::vector<double>* ValuesGrammar::getValues()
{
    std::vector<double>* res;
    res = this->expr();
    if(this->chromosomeProcessor->endByWrap()){
        delete res;
        return new std::vector<double>();
    } else{
        return res;
    }

}

std::vector<double>* ValuesGrammar::expr() {
    if(this->chromosomeProcessor->endByWrap()) return new std::vector<double>();
    switch (this->chromosomeProcessor->getCodon() % 6){
        case 0:
            this->chromosomeProcessor->consumeCodon();
            return VectorFunctions::mul(this->kg(), this->sign()*this->real());
        case 1:
            this->chromosomeProcessor->consumeCodon();
            return VectorFunctions::add(VectorFunctions::mul(this->kg(), this->sign()*this->real()), this->expr());
        case 2:
            this->chromosomeProcessor->consumeCodon();
            return VectorFunctions::mul(this->kp(), this->sign()*this->real());
        case 3:
            this->chromosomeProcessor->consumeCodon();
            return VectorFunctions::add(VectorFunctions::mul(this->kp(), this->sign()*this->real()), this->expr());
        case 4:
            this->chromosomeProcessor->consumeCodon();
            return VectorFunctions::mul(this->ks(), this->sign()*this->real());
        case 5:
            this->chromosomeProcessor->consumeCodon();
            return VectorFunctions::add(VectorFunctions::mul(this->ks(), this->sign()*this->real()), this->expr());
        default:
            return new std::vector<double>();
    }

}

std::vector<double>* ValuesGrammar::kg() {
    if(this->chromosomeProcessor->endByWrap()) return new std::vector<double>();
    auto* res = new std::vector<double>();
    double d1 = this->real();
    double d2 = this->real();
    this->null();
    for(double x : *Configuration::x){
        res->push_back(exp(-(d1*pow(d2-x, 2))));
    }
    return res;
}

std::vector<double>* ValuesGrammar::kp() {
    if(this->chromosomeProcessor->endByWrap()) return new std::vector<double>();
    auto* res = new std::vector<double>();
    double d1 = this->real();
    double d2 = this->real();
    int g = this->degree();
    for(double x : *Configuration::x){
        res->push_back(pow(d1*x+d2, g));
    }
    return res;
}

std::vector<double>* ValuesGrammar::ks() {
    if(this->chromosomeProcessor->endByWrap()) return new std::vector<double>();
    auto* res = new std::vector<double>();
    double d1 = this->real();
    double d2 = this->real();
    this->null();
    for(double x : *Configuration::x){
        res->push_back(tanh(d1*x+d2));
    }
    return res;
}

double ValuesGrammar::sign() {
    if(this->chromosomeProcessor->endByWrap()) return std::numeric_limits<double>::min();
    switch (this->chromosomeProcessor->getCodon() % 2){
        case 0:
            this->chromosomeProcessor->consumeCodon();
            return 1.0;
        case 1:
            this->chromosomeProcessor->consumeCodon();
            return -1.0;
        default:
            return std::numeric_limits<double>::min();
    }
}

double ValuesGrammar::real() {
    if(this->chromosomeProcessor->endByWrap()) return std::numeric_limits<double>::min();
    double d = this->oneNine() + this->zeroNine()*0.1;
    double exp = pow(10, this->sign()*this->zeroNine());
    return d*exp;
}

void ValuesGrammar::null() {
    if(this->chromosomeProcessor->endByWrap()) return;
    this->chromosomeProcessor->consumeCodon();
}

int ValuesGrammar::degree() {
    if(this->chromosomeProcessor->endByWrap()) return std::numeric_limits<int>::min();
    int res = this->chromosomeProcessor->getCodon() % 5;
    this->chromosomeProcessor->consumeCodon();
    return res;
}

int ValuesGrammar::oneNine() {
    if(this->chromosomeProcessor->endByWrap()) return std::numeric_limits<int>::min();
    int res = (this->chromosomeProcessor->getCodon() % 9) + 1;
    this->chromosomeProcessor->consumeCodon();
    return res;
}

int ValuesGrammar::zeroNine() {
    if(this->chromosomeProcessor->endByWrap()) return std::numeric_limits<int>::min();
    int res = this->chromosomeProcessor->getCodon() % 10;
    this->chromosomeProcessor->consumeCodon();
    return res;
}

ValuesGrammar::~ValuesGrammar() {
    delete this->chromosomeProcessor;
}
