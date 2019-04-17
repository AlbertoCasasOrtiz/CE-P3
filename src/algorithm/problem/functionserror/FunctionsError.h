//
// Created by alber on 17/04/2019.
//

#ifndef CE_ACTIVIDAD_3_FUNCTIONSERROR_H
#define CE_ACTIVIDAD_3_FUNCTIONSERROR_H


#include <vector>

class FunctionsError {
public:
    static double weightedMeanSquaredError(std::vector<double> f1, std::vector<double> f2, double u, double k0, double k1){
        double res = 0;
        for(int i = 0; i < f1.size(); i++){
            if(pow(f1[i] - f2[i], 2) <= u)
                res += k0*abs(f1[i] - f2[i]);
            else
                res += k1*abs(f1[i] - f2[i])
        }
    }
};


#endif //CE_ACTIVIDAD_3_FUNCTIONSERROR_H
