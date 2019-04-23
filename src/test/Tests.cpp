//
// Created by alber on 24/04/2019.
//

#include <iostream>
#include "Tests.h"
#include "../algorithm/problem/grammar/ExpressionGrammar.h"
#include "../algorithm/problem/grammar/ValuesGrammar.h"
#include "../algorithm/configuration/Configuration.h"

bool Tests::testGrammars() {
    auto* chromosome = new std::vector<int>();

    chromosome->push_back(1);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);
    chromosome->push_back(0);

    Configuration::x = new std::vector<double>();
    Configuration::wrapping = 1;
    Configuration::x->push_back(0);
    ExpressionGrammar expressionGrammar = ExpressionGrammar(chromosome);
    std::cout << expressionGrammar.getExpression() << std::endl;
    ValuesGrammar valuesGrammar = ValuesGrammar(chromosome);

    for(double i : *valuesGrammar.getValues())
        std::cout << i << std::endl;

    delete chromosome;
    return false;
}
