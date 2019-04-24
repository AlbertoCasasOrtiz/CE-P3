//
// Created by Alberto Casas Ortiz.
//

#ifndef CONFIGURATIONPARSERS_H

    #include <string>
    #include "../operators/mutation/Mutation.h"
    #include "../operators/reproduction/Reproduction.h"
    #include "../operators/selectionparents/SelectionParents.h"
    #include "../operators/selectionsurvivors/SelectionSurvivors.h"
    #include "../problem/Problem.h"

#define CONFIGURATIONPARSERS_H


/**
 * Class containing parsers for configuration file values.
 */
class ConfigurationParsers {
public:
    /**
     * Parse an integer value from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed integer value.
     */
    static int parseInt(const std::string& line);

    /**
     * Parse a double value from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed double value.
     */
    static double parseDouble(const std::string& line);

    /**
     * Parse a boolean value from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed boolean value.
     */
    static bool parseBoolean(const std::string& line);

    /**
     * Parse a Problem type from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed Problem type.
     */
    static Problem* parseProblem(const std::string& line);

    /**
     * Parse a Mutation method from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed Mutation method.
     */
    static Mutation* parseMutation(const std::string& line);

    /**
     * Parse a Reproduction method from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed Reproduction method.
     */
    static Reproduction* parseReproduction(const std::string& line);

    /**
     * Parse a Selection of Parents method from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed Selection of Parents method.
     */
    static SelectionParents* parseSelectionParents(const std::string& line);

    /**
     * Parse a Selection of Survivors method from configuration file.
     * @param line Line of the configuration file.
     * @return Parsed Selection of Survivors method.
     */
    static SelectionSurvivors* parseSelectionSurvivors(const std::string& line);
};


#endif //CONFIGURATIONPARSERS_H
