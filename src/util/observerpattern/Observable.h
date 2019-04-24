//
// Created by Alberto Casas Ortiz.
//

#ifndef OBSERVABLE_H

    #include "Observer.h"
    #include "vector"

#define OBSERVABLE_H



class Observable {
protected:
    std::vector<Observer> observers;
public:
    Observable();
    void addObserver(Observer observer);
    void removeObserver(Observer observer);
    void clear();
    virtual void notifyObservers() = 0;
};


#endif //OBSERVABLE_H
