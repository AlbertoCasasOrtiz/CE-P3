//
// Created by alber on 19/04/2019.
//

#ifndef CE_ACTIVIDAD_3_TIMER_H

#include <ctime>
#define CE_ACTIVIDAD_3_TIMER_H


class Timer {
private:
    clock_t start;
    clock_t stop;
public:
    Timer();
    void tic();
    void tac();
    double getTime();
};


#endif //CE_ACTIVIDAD_3_TIMER_H
