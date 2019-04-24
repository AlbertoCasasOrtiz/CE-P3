//
// Created by Alberto Casas Ortiz.
//

#ifndef FUNCTIONSERROR_H

    #include <vector>
    #include <cmath>
    #include <stdlib.h>

#define FUNCTIONSERROR_H


/**
 * Error functions to evaluate results.
 */
class FunctionsError {
public:
    /**
     * Weighted mean squared error function.
     * @param f1 Results of a function.
     * @param f2 REsult of another function.
     * @param u Umbral.
     * @param k0 Weight 1.
     * @param k1 Weight 2.
     * @return Error between f1 and f2.
     */
    static double weightedMeanSquaredError(std::vector<double>* f1, std::vector<double>* f2, double u, double k0, double k1);
};


#endif //FUNCTIONSERROR_H
