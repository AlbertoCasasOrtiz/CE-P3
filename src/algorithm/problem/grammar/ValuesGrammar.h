//
// Created by Alberto Casas Ortiz.
//

#ifndef VALUESGRAMMAR_H

    #include "auxiliar/ChromosomeProcessor.h"

#define VALUESGRAMMAR_H


/**
 * A set of functions describing the grammar. Return a result of the expression.
 */
class ValuesGrammar {
public:
    /** A processor of a chromosome. */
    ChromosomeProcessor* chromosomeProcessor;

    /**
     * Get result encoded in the chromosome.
     * @return Result encoded in the chromosome.
     */
    std::vector<double>* getValues();

    /**
     * Constructor for the class ValuesGrammar.
     * @param chromosome Chromosome with encoded results.
     */
    explicit ValuesGrammar(std::vector<int>* chromosome);

    /**
     * Destructor for class ValuesGrammar.
     */
    ~ValuesGrammar();
private:
    /**
     * Expr node of the grammar.
     * @return Expr node of the grammar.
     */
    std::vector<double>* expr();

    /**
     * Kg node of the grammar.
     * @return Kg node of the grammar.
     */
    std::vector<double>* kg();

    /**
     * Kp node of the grammar.
     * @return Kp node of the grammar.
     */
    std::vector<double>* kp();

    /**
     * Ks node of the grammar.
     * @return Ks node of the grammar.
     */
    std::vector<double>* ks();

    /**
     * Sign node of the grammar.
     * @return Sign node of the grammar.
     */
    double sign();

    /**
     * Real node of the grammar.
     * @return Real node of the grammar.
     */
    double real();

    /**
     * Null node of the grammar.
     * @return Null node of the grammar.
     */
    void null();

    /**
     * Degree node of the grammar.
     * @return Degree node of the grammar.
     */
    int degree();

    /**
     * OneNine node of the grammar.
     * @return OneNine node of the grammar.
     */
    int oneNine();

    /**
     * ZeroNine node of the grammar.
     * @return ZeroNine node of the grammar.
     */
    int zeroNine();
};


#endif //VALUESGRAMMAR_H
