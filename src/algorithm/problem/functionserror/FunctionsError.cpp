//
// Created by alber on 17/04/2019.
//

#include "FunctionsError.h"

double FunctionsError::weightedMeanSquaredError(std::vector<double> *f1, std::vector<double> *f2, double u, double k0, double k1) {
    double res = 0;
    for(int i = 0; i < f1->size(); i++){
        if(pow((*f1)[i] - (*f2)[i], 2) <= u)
            res += k0*abs((*f1)[i] - (*f2)[i]);
        else
            res += k1*abs((*f1)[i] - (*f2)[i]);
    }
    return res;
}
