//
// Created by Alberto Casas Ortiz.
//

#ifndef VECTORFUNCTIONS_H

    #include <vector>

#define VECTORFUNCTIONS_H


/**
 * A set of functions for operate with double and integer vectors.
 */
class VectorFunctions {
public:
    /**
     * Add values of two vectors.
     * @param vector1 Vector 1.
     * @param vector2 Vector 2.
     * @return Vector with the addition of vector1 and vector2.
     */
    static std::vector<double>* add(std::vector<double>* vector1, std::vector<double>* vector2);

    /**
     * Add a value to all elements of a vector.
     * @param vector1 Vector 1.
     * @param d1 Value 1.
     * @return Vector with the addition of d1 to all elements of the vector1.
     */
    static std::vector<double>* add(std::vector<double>* vector1, double d1);

    /**
     * Mul values of two vectors.
     * @param vector1 Vector 1.
     * @param vector2 Vector 2.
     * @return Vector with the multiplication of vector1 and vector2.
     */
    static std::vector<double>* mul(std::vector<double>* vector1, std::vector<double>* vector2);

    /**
     * Mul a value to all elements of a vector.
     * @param vector1 Vector 1.
     * @param d1 Value 1.
     * @return Vector with the multiplication of d1 to all elements of the vector1.
     */
    static std::vector<double>* mul(std::vector<double>* vector1, double d1);
};


#endif //VECTORFUNCTIONS_H
