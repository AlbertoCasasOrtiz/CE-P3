//
// Created by alber on 15/04/2019.
//

#ifndef CE_ACTIVIDAD_3_REPRODUCTION_H
#define CE_ACTIVIDAD_3_REPRODUCTION_H


#include "../../individual/IndividualSet.h"

class Reproduction {
public:
    virtual IndividualSet reproduce(IndividualSet parents) = 0;
    virtual ~Reproduction() = default;
};


#endif //CE_ACTIVIDAD_3_REPRODUCTION_H
