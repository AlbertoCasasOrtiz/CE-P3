cmake_minimum_required(VERSION 3.13)
project(CE_Actividad_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(CE_Actividad_3 main.cpp src/algorithm/GeneticAlgorithm.cpp src/algorithm/GeneticAlgorithm.h src/util/Observable.cpp src/util/Observable.h src/algorithm/individual/IndividualSet.cpp src/algorithm/individual/IndividualSet.h src/algorithm/individual/Individual.cpp src/algorithm/individual/Individual.h src/util/Observer.cpp src/util/Observer.h src/algorithm/configuration/Configuration.cpp src/algorithm/configuration/Configuration.h)