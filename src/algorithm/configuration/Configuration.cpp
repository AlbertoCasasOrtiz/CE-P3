//
// Created by alber on 14/04/2019.
//

#include "Configuration.h"
#include "ConfigurationParsers.h"

#include <iostream>
#include <fstream>



void Configuration::loadConfiguration() {
    std::ifstream file(Configuration::pathConfig, std::ios::in);
    std::string sline;

    if(file.is_open()){
        int line = 1;
        while(std::getline(file, sline)){
            parseLine(sline, line);
            line++;
        }
    } else {
        //TODO error
    }

    file.close();

}

void Configuration::parseLine(std::string line, int nLine) {
    std::string delimiter = " :";
    std::string key = line.substr(0, line.find(delimiter));
    std::string value = line.substr(line.find(delimiter)+delimiter.size()-1, line.size());
    if(key == "problem_config") {
        Configuration::pathConfig = value;
    }else if(key == "number_executions"){
        Configuration::numExecutions = ConfigurationParsers::parseInt(line);
    }else if(key == "problem"){
        //TODO
        Configuration::problem = value;
    }else if(key == "population_size"){
        Configuration::populationSize = ConfigurationParsers::parseInt(line);
    }else if(key == "offspring_size"){
        Configuration::offspringSize = ConfigurationParsers::parseInt(line);
    }else if(key == "number_generations"){
        Configuration::maxNumGenerations = ConfigurationParsers::parseInt(line);
    }else if(key == "selection_parents"){
        Configuration::selectionParents = ConfigurationParsers::parseSelectionParents(line);
    }else if(key == "reproduction"){
        Configuration::reproduction = ConfigurationParsers::parseReproduction(line);
    }else if(key == "pRep"){
        Configuration::pRep = ConfigurationParsers::parseDouble(line);
    }else if(key == "mutation"){
        Configuration::mutation = ConfigurationParsers::parseMutation(line);
    }else if(key == "pMut"){
        Configuration::pMut = ConfigurationParsers::parseDouble(line);
    }else if(key == "selection_survivors"){
        Configuration::selectionSurvivors = ConfigurationParsers::parseSelectionSurvivors(line);
    }else if(key == "elitism"){
        Configuration::elitism = ConfigurationParsers::parseBoolean(line);
    }else if(key == "max_codon_size"){
        Configuration::maxCodonValue = ConfigurationParsers::parseInt(line);
    }else if(key == "max_chromosome_size"){
        Configuration::maxChromosomeSize = ConfigurationParsers::parseInt(line);
    }else if(key == "wrapping"){
        Configuration::wrapping = ConfigurationParsers::parseInt(line);
    }else if(key == "min_interval"){
        Configuration::minInterval = ConfigurationParsers::parseInt(line);
    }else if(key == "max_interval"){
        Configuration::maxInterval = ConfigurationParsers::parseInt(line);
    }else if(key == "samples"){
        Configuration::samples = ConfigurationParsers::parseInt(line);
    }else if(key == "function"){
        Configuration::function = ConfigurationParsers::parseInt(line);
    }


}

void Configuration::generateX() {
    double length = Configuration::maxInterval-Configuration::minInterval;
    double sampleSize = length/Configuration::samples;
    double cont = Configuration::minInterval;
    for(int i = 0; i < Configuration::samples; i++){
        Configuration::x.push_back(cont);
        cont += sampleSize;
    }
}

Configuration::Configuration() {
    this->loadConfiguration();
    this->generateX();
}

Configuration::~Configuration() {
    delete this->problem;
    delete Configuration::selectionParents;
    delete Configuration::reproduction;
    delete Configuration::mutation;
    delete Configuration::selectionSurvivors;
}


