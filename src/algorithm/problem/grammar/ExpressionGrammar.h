//
// Created by Alberto Casas Ortiz.
//

#ifndef EXPRESSIONGRAMMAR_H

    #include <string>
    #include "auxiliar/ChromosomeProcessor.h"

#define EXPRESSIONGRAMMAR_H


/**
 * A set of functions describing the grammar. Return a string with the expression.
 */
class ExpressionGrammar {
public:
    /** A processor of a chromosome. */
    ChromosomeProcessor* chromosomeProcessor;

    /**
     * Get an expression encoded in a chromosome.
     * @return Expression encoded in a chromosome.
     */
    std::string getExpression();

    /**
     * Constructor for class ExpressionGrammar.
     * @param chromosome Chromosome encoding a expression.
     */
    explicit ExpressionGrammar(std::vector<int>* chromosome);

    /**
     * Destructor for class ExpressionGrammar.
     */
    ~ExpressionGrammar();
private:
    /**
     * Expr node of the grammar.
     * @return Expr node of the grammar.
     */
    std::string expr();

    /**
     * Kg node of the grammar.
     * @return Kg node of the grammar.
     */
    std::string kg();

    /**
     * Kp node of the grammar.
     * @return Kp node of the grammar.
     */
    std::string kp();

    /**
     * Ks node of the grammar.
     * @return Ks node of the grammar.
     */
    std::string ks();

    /**
     * Sign node of the grammar.
     * @return Sign node of the grammar.
     */
    std::string sign();

    /**
     * Real node of the grammar.
     * @return Real node of the grammar.
     */
    std::string real();

    /**
     * Null node of the grammar.
     * @return Null node of the grammar.
     */
    std::string null();

    /**
     * Degree node of the grammar.
     * @return Degree node of the grammar.
     */
    std::string degree();

    /**
     * OneNine node of the grammar.
     * @return OneNine node of the grammar.
     */
    std::string oneNine();

    /**
     * ZeroNine node of the grammar.
     * @return ZeroNine node of the grammar.
     */
    std::string zeroNine();
};


#endif //EXPRESSIONGRAMMAR_H
