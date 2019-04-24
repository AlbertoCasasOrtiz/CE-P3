//
// Created by Alberto Casas Ortiz.
//

#ifndef RANDOMGENERATOR_H

    #include <random>
    #include <sstream>

#define RANDOMGENERATOR_H


/**
 * Random number generator class.
 */
class RandomGenerator {
private:
    /** Seeder of the random number generator. */
    static std::mt19937 mt;
public:
    /**
     * Get a double random value from an interval.
     * @param start Start value of the interval.
     * @param end End value of the interval.
     * @return Double random value.
     */
    double static getDouble(double start, double end);

    /**
     * Get an integer random value from an interval.
     * @param start Start value of the interval.
     * @param end End value of the interval.
     * @return Integer random value.
     */
    int static getInt(int start, int end);
};


#endif //RANDOMGENERATOR_H
