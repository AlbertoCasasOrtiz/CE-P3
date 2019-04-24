//
// Created by Alberto Casas Ortiz.
//

#ifndef FUNCTIONS_H

    #include <vector>

#define FUNCTIONS_H


/**
 * Set of functions to evaluate the algorithm.
 */
class Functions {
public:
    /**
     * Execute a function.
     * @param function Number of function.
     * @return Result y of the function.
     */
    static std::vector<double>* executeFunction(int function);

    /**
     * Execute function 0.
     * @return Result y of the function.
     */
    static std::vector<double>* function0();

    /**
     * Execute function 1.
     * @return Result y of the function.
     */
    static std::vector<double>* function1();

    /**
     * Execute function 2.
     * @return Result y of the function.
     */
    static std::vector<double>* function2();

    /**
     * Execute function 3.
     * @return Result y of the function.
     */
    static std::vector<double>* function3();

    /**
     * Execute function 4.
     * @return Result y of the function.
     */
    static std::vector<double>* function4();

    /**
     * Execute function 5.
     * @return Result y of the function.
     */
    static std::vector<double>* function5();
};


#endif //FUNCTIONS_H
