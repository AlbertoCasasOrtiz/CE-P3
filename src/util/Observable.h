//
// Created by alber on 13/04/2019.
//

#ifndef CE_ACTIVIDAD_3_OBSERVABLE_H
#include "Observer.h"
#include "vector"
#define CE_ACTIVIDAD_3_OBSERVABLE_H



class Observable {
protected:
    std::vector<Observer> observers;
public:
    Observable();
    void addObserver(Observer observer);
    void removeObserver(Observer observer);
    void clear();
    virtual void notifyObservers();
};


#endif //CE_ACTIVIDAD_3_OBSERVABLE_H
