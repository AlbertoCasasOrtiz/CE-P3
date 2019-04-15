//
// Created by alber on 14/04/2019.
//

#ifndef CE_ACTIVIDAD_3_OBSERVER_H
#include <string>
#define CE_ACTIVIDAD_3_OBSERVER_H



class Observer {
public:
    void update(void* object);
    std::string getType();
};


#endif //CE_ACTIVIDAD_3_OBSERVER_H
