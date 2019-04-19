//
// Created by alber on 18/04/2019.
//

#ifndef CE_ACTIVIDAD_3_CHROMOSOMEPROCESSOR_H
#define CE_ACTIVIDAD_3_CHROMOSOMEPROCESSOR_H


#include <vector>

class ChromosomeProcessor {
private:
    std::vector<int>* chromosome;
    int position;
    int consumed;
    int currentWrap;
public:
    explicit ChromosomeProcessor(std::vector<int>* array);
    int getInteger();
    void consumeCodon();
    bool endByWrap();
};


#endif //CE_ACTIVIDAD_3_CHROMOSOMEPROCESSOR_H
