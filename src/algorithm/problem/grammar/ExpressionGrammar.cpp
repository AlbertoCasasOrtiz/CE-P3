#include <utility>

//
// Created by alber on 18/04/2019.
//

#include "ExpressionGrammar.h"

ExpressionGrammar::ExpressionGrammar(std::vector<int>* chromosome) {
    this->chromosomeProcessor = new ChromosomeProcessor(chromosome);
}

std::string ExpressionGrammar::getExpression() {
    std::string str = this->expr();
    if(this->chromosomeProcessor->endByWrap()) {
        return "";
    }else{
        return str;
    }
    return this->chromosomeProcessor->endByWrap() ? "" : str;
}

std::string ExpressionGrammar::expr() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    this->chromosomeProcessor->consumeCodon();
    switch (this->chromosomeProcessor->getInteger() % 6){
        case 0:
            return this->sign()+this->real()+this->kg();
        case 1:
            return this->sign()+this->real()+this->kg()+this->expr();
        case 2:
            return this->sign()+this->real()+this->kp();
        case 3:
            return this->sign()+this->real()+this->kp()+this->expr();
        case 4:
            return this->sign()+this->real()+this->ks();
        case 5:
            return this->sign()+this->real()+this->ks()+this->expr();
        default:
            //TODO ERROR
            return "";
    }
}

std::string ExpressionGrammar::kg() {
    return "Kg("+this->real()+","+this->real()+","+this->null()+")";
}

std::string ExpressionGrammar::kp() {
    return "Kp("+this->real()+","+this->real()+","+this->degree()+")";
}

std::string ExpressionGrammar::ks() {
    return "Ks("+this->real()+","+this->real()+","+this->null()+")";
}

std::string ExpressionGrammar::sign() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    this->chromosomeProcessor->consumeCodon();
    switch (this->chromosomeProcessor->getInteger() % 2){
        case 0:
            return "+";
        case 1:
            return "-";
    }
    //TODO Error
    return "";
}

std::string ExpressionGrammar::real() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    return this->oneNine()+"."+this->zeroNine()+"E"+this->sign()+this->zeroNine();
}

std::string ExpressionGrammar::null() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    this->chromosomeProcessor->consumeCodon();
    return "";
}

std::string ExpressionGrammar::degree() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    this->chromosomeProcessor->consumeCodon();
    return std::to_string(this->chromosomeProcessor->getInteger() % 5);
}

std::string ExpressionGrammar::oneNine() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    this->chromosomeProcessor->consumeCodon();
    return std::to_string((this->chromosomeProcessor->getInteger() % 9) + 1);

}

std::string ExpressionGrammar::zeroNine() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    this->chromosomeProcessor->consumeCodon();
    return std::to_string(this->chromosomeProcessor->getInteger() % 10);
}

ExpressionGrammar::~ExpressionGrammar() {
    delete this->chromosomeProcessor;
}
