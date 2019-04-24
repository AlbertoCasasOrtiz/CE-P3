//
// Created by Alberto Casas Ortiz.
//

#ifndef OBSERVER_H

    #include <string>

#define OBSERVER_H



class Observer {
public:
    void update(void* object);
    std::string getType();
};


#endif //OBSERVER_H
