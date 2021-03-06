#include <utility>
//
// Created by Alberto Casas Ortiz.
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
}

std::string ExpressionGrammar::expr() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    switch (this->chromosomeProcessor->getCodon() % 6){
        case 0:
            this->chromosomeProcessor->consumeCodon();
            return this->sign()+this->real()+this->kg();
        case 1:
            this->chromosomeProcessor->consumeCodon();
            return this->sign()+this->real()+this->kg()+this->expr();
        case 2:
            this->chromosomeProcessor->consumeCodon();
            return this->sign()+this->real()+this->kp();
        case 3:
            this->chromosomeProcessor->consumeCodon();
            return this->sign()+this->real()+this->kp()+this->expr();
        case 4:
            this->chromosomeProcessor->consumeCodon();
            return this->sign()+this->real()+this->ks();
        case 5:
            this->chromosomeProcessor->consumeCodon();
            return this->sign()+this->real()+this->ks()+this->expr();
        default:
            //Unreachable
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
    switch (this->chromosomeProcessor->getCodon() % 2){
        case 0:
            this->chromosomeProcessor->consumeCodon();
            return "+";
        case 1:
            this->chromosomeProcessor->consumeCodon();
            return "-";
    }
    //Unreachable
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
    std::string str = std::to_string(this->chromosomeProcessor->getCodon() % 5);
    this->chromosomeProcessor->consumeCodon();
    return str;
}

std::string ExpressionGrammar::oneNine() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    std::string str = std::to_string((this->chromosomeProcessor->getCodon() % 9) + 1);
    this->chromosomeProcessor->consumeCodon();
    return str;

}

std::string ExpressionGrammar::zeroNine() {
    if(this->chromosomeProcessor->endByWrap()) return "";
    std::string str = std::to_string(this->chromosomeProcessor->getCodon() % 10);
    this->chromosomeProcessor->consumeCodon();
    return str;
}

ExpressionGrammar::~ExpressionGrammar() {
    delete this->chromosomeProcessor;
}
