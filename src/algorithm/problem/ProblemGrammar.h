//
// Created by Alberto Casas Ortiz.
//

#ifndef PROBLEMGRAMMAR_H

    #include "Problem.h"
    #include <string>

#define PROBLEMGRAMMAR_H


class ProblemGrammar: public Problem{
public:
    /**
     * Return if the problem is a maximization problem.
     * @return True if maximization problem.
     */
    bool isMaximization() override;

    /**
     * Execute the function of the problem.
     * @param parameters Chromosome to evaluate.
     * @return Fitness of the chromosome.
     */
    double function(std::vector<int>* parameters) override;

    /**
     * Decode the chromosome and get the results of apply x over the resulting expression.
     * @param parameters Chromosome to evaluate.
     * @return Results of apply x over the resulting expression.
     */
    std::vector<double>* decode(std::vector<int>* parameters) override;

    /**
     * Get expression encoded in the chromosome.
     * @param parameters Chromosome to evaluate.
     * @return Expression encoded in the chromosome.
     */
    std::string getExpression(std::vector<int>* parameters) override;
};


#endif //PROBLEMGRAMMAR_H
