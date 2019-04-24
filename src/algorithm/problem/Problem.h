//
// Created by Alberto Casas Ortiz.
//

#ifndef PROBLEM_H

    #include <vector>
    #include <string>

#define PROBLEM_H


/**
 * Problem definition for the algorithm.
 */
class Problem {
public:
    /**
     * Evaluate a chromosome.
     * @param parameters Chromosome to evaluate.
     * @return Fitness of the chromosome.
     */
    double evaluate(std::vector<int>* parameters);

    /**
     * Return if the problem is a maximization problem.
     * @return True if maximization problem.
     */
    virtual bool isMaximization() = 0;

    /**
     * Execute the function of the problem.
     * @param parameters Chromosome to evaluate.
     * @return Fitness of the chromosome.
     */
    virtual double function(std::vector<int>* parameters) = 0;

    /**
     * Decode the chromosome and get the results of apply x over the resulting expression.
     * @param parameters Chromosome to evaluate.
     * @return Results of apply x over the resulting expression.
     */
    virtual std::vector<double>* decode(std::vector<int>* parameters) = 0;

    /**
     * Get expression encoded in the chromosome.
     * @param parameters Chromosome to evaluate.
     * @return Expression encoded in the chromosome.
     */
    virtual std::string getExpression(std::vector<int>* parameters) = 0;
};


#endif //PROBLEM_H
