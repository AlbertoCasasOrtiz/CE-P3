//
// Created by alber on 17/04/2019.
//

#include "Functions.h"
#include "../../configuration/Configuration.h"
#include <cmath>

std::vector<double> Functions::executeFunction(int function){
    switch (function){
        case 0:
            return Functions::function0();
        case 1:
            return Functions::function1();
        case 2:
            return Functions::function2();
        case 3:
            return Functions::function3();
        case 4:
            return Functions::function4();
        case 5:
            return Functions::function5();
        default:
            return std::vector<double>();
    }
}

std::vector<double> Functions::function0() {
    std::vector<double> f;
    for(double x : Configuration::x){
        double res = 8*exp(-2*pow(x-2, 2));
        res += (2*x+1);
        res += 3*tanh(3*x+2);
        f.push_back(res);
    }
    return f;
}

std::vector<double> Functions::function1() {
    std::vector<double> f;
    for(double x : Configuration::x){
        double res = 2*exp(-2*pow(x-1, 2));
        res -= exp(pow(x-1, 2));
        f.push_back(res);
    }
    return f;
}

std::vector<double> Functions::function2() {
    std::vector<double> f;
    for(double x : Configuration::x){
        double res = sqrt(x);
        f.push_back(res);
    }
    return f;
}

std::vector<double> Functions::function3() {
    std::vector<double> f;
    for(double x : Configuration::x){
        double res = exp(-x)*sin(2*x);
        f.push_back(res);
    }
    return f;
}

std::vector<double> Functions::function4() {
    std::vector<double> f;
    for(double x : Configuration::x){
        double res = log(log(x));
        f.push_back(res);
    }
    return f;
}

std::vector<double> Functions::function5() {
    std::vector<double> f;
    for(double x : Configuration::x){
        double res = 6*exp(-2*x);
        res+=2*sin(x);
        res-=cos(x);
        f.push_back(res);
    }
    return f;
}
