//
// Created by Alberto Casas Ortiz.
//

#ifndef TIMER_H

    #include <ctime>

#define TIMER_H


/**
 * Timer to measure execution times.
 */
class Timer {
private:
    /** Start time of the timer. */
    clock_t start;
    /** End time of the timer. */
    clock_t stop;
public:
    /**
     * Constructor for the class Timer.
     */
    Timer();

    /**
     * Start counting time.
     */
    void tic();

    /**
     * Stop counting time.
     */
    void tac();

    /**
     * Get time in seconds.
     * @return Time in seconds.
     */
    double getTime();
};


#endif //TIMER_H
