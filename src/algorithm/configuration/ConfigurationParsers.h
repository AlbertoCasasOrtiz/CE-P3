//
// Created by alber on 17/04/2019.
//

#ifndef CE_ACTIVIDAD_3_CONFIGURATIONPARSERS_H
#define CE_ACTIVIDAD_3_CONFIGURATIONPARSERS_H


#include <string>
#include "../operators/mutation/Mutation.h"
#include "../operators/reproduction/Reproduction.h"
#include "../operators/selectionparents/SelectionParents.h"
#include "../operators/selectionsurvivors/SelectionSurvivors.h"
#include "../problem/Problem.h"

class ConfigurationParsers {
public:
    static int parseInt(const std::string& line);
    static double parseDouble(const std::string& line);
    static bool parseBoolean(const std::string& line);
    static Problem* parseProblem(const std::string& line);
    static Mutation* parseMutation(const std::string& line);
    static Reproduction* parseReproduction(const std::string& line);
    static SelectionParents* parseSelectionParents(const std::string& line);
    static SelectionSurvivors* parseSelectionSurvivors(const std::string& line);
};


#endif //CE_ACTIVIDAD_3_CONFIGURATIONPARSERS_H
