//
// Created by Alberto Casas Ortiz.
//

#ifndef CHROMOSOMEPROCESSOR_H

    #include <vector>

#define CHROMOSOMEPROCESSOR_H


/**
 * Chromosome processor for grammar.
 */
class ChromosomeProcessor {
private:
    /** Chromosome from an individual. */
    std::vector<int>* chromosome;
    /** Position of the processor. */
    int position;
    /** Number of consumed codons. */
    int consumed;
    /** Current wrap. */
    int currentWrap;
public:
    /**
     * Constructor for class ChromosomeProcessor.
     * @param array Chromosome taken from an individual.
     */
    explicit ChromosomeProcessor(std::vector<int>* array);

    /**
     * Destructor for class ChromosomeProcessor.
     */
    ~ChromosomeProcessor();

    /**
     * Gec current codon.
     * @return Current codon.
     */
    int getCodon();

    /**
     * Consume a codon.
     */
    void consumeCodon();

    /**
     * Return if we have passed the wrap limit.
     * @return True if we have passed the wrap limit.
     */
    bool endByWrap();
};


#endif //CHROMOSOMEPROCESSOR_H
