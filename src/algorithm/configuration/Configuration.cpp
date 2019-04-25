//
// Created by Alberto Casas Ortiz.
//

#include "Configuration.h"
#include "ConfigurationParsers.h"

#include <iostream>
#include <fstream>

std::string Configuration::executionName;
std::string Configuration::problemName;
Problem* Configuration::problem;
int Configuration::numExecutions;
int Configuration::populationSize;
int Configuration::offspringSize;
int Configuration::maxNumGenerations;
int Configuration::maxCodonValue;
int Configuration::wrapping;
int Configuration::minInterval;
int Configuration::maxInterval;
int Configuration::samples;
int Configuration::function;
std::vector<double>* Configuration::x;
int Configuration::maxChromosomeSize;
std::string Configuration::nameSelectionParents;
SelectionParents* Configuration::selectionParents;
std::string Configuration::nameReproduction;
Reproduction* Configuration::reproduction;
double Configuration::pRep;
std::string Configuration::nameMutation;
Mutation* Configuration::mutation;
double Configuration::pMut;
std::string Configuration::nameSelectionSurvivors;
SelectionSurvivors* Configuration::selectionSurvivors;
bool Configuration::elitism;
int Configuration::numElitism;

void Configuration::loadConfiguration() {
    std::string pathConfig = "config/config.cfg";
    std::ifstream file(pathConfig);
    std::string sline;

    if(file.is_open()){
        int line = 1;
        while(std::getline(file, sline)){
            parseLine(sline, line);
            line++;
        }
    } else {
        std::cerr << "There was an error reading configuration file." << std::endl;
    }

    Configuration::generateX();
    file.close();
}

void Configuration::parseLine(const std::string& line, int nLine) {
    std::string delimiter = ": ";
    std::string key = line.substr(0, line.find(delimiter));
    std::string value = line.substr(line.find(delimiter)+delimiter.size(), line.size());
    if(key == "name_execution") {
        Configuration::executionName = value;
    }else if(key == "number_executions"){
        Configuration::numExecutions = ConfigurationParsers::parseInt(value);
    }else if(key == "problem"){
        Configuration::problem = ConfigurationParsers::parseProblem(value);
        Configuration::problemName = value;
    }else if(key == "population_size"){
        Configuration::populationSize = ConfigurationParsers::parseInt(value);
    }else if(key == "offspring_size"){
        Configuration::offspringSize = ConfigurationParsers::parseInt(value);
    }else if(key == "number_generations"){
        Configuration::maxNumGenerations = ConfigurationParsers::parseInt(value);
    }else if(key == "selection_parents"){
        Configuration::selectionParents = ConfigurationParsers::parseSelectionParents(value);
        Configuration::nameSelectionParents = value;
    }else if(key == "reproduction"){
        Configuration::reproduction = ConfigurationParsers::parseReproduction(value);
        Configuration::nameReproduction = value;
    }else if(key == "pRep"){
        Configuration::pRep = ConfigurationParsers::parseDouble(value);
    }else if(key == "mutation"){
        Configuration::mutation = ConfigurationParsers::parseMutation(value);
        Configuration::nameMutation = value;
    }else if(key == "pMut"){
        Configuration::pMut = ConfigurationParsers::parseDouble(value);
    }else if(key == "selection_survivors"){
        Configuration::selectionSurvivors = ConfigurationParsers::parseSelectionSurvivors(value);
        Configuration::nameSelectionSurvivors = value;
    }else if(key == "elitism"){
        Configuration::elitism = ConfigurationParsers::parseBoolean(value);
    }else if(key == "max_codon_size"){
        Configuration::maxCodonValue = ConfigurationParsers::parseInt(value);
    }else if(key == "max_chromosome_size"){
        Configuration::maxChromosomeSize = ConfigurationParsers::parseInt(value);
    }else if(key == "wrapping"){
        Configuration::wrapping = ConfigurationParsers::parseInt(value);
    }else if(key == "min_interval"){
        Configuration::minInterval = ConfigurationParsers::parseInt(value);
    }else if(key == "max_interval"){
        Configuration::maxInterval = ConfigurationParsers::parseInt(value);
    }else if(key == "samples"){
        Configuration::samples = ConfigurationParsers::parseInt(value);
    }else if(key == "function") {
        Configuration::function = ConfigurationParsers::parseInt(value);
    }else if(key == "num_elitism"){
        Configuration::numElitism = ConfigurationParsers::parseInt(value);
    } else {
        std::cout << "Error in configuration file in line: " << std::to_string(nLine) << std::endl;
        std::cout << "Key: " << key << std::endl;
        std::cout << "Value: " << value << std::endl;
    }
}

void Configuration::generateX() {
    Configuration::x = new std::vector<double>();
    double length = Configuration::maxInterval-Configuration::minInterval;
    double sampleSize = length/Configuration::samples;
    double cont = Configuration::minInterval;
    for(int i = 0; i < Configuration::samples; i++){
        Configuration::x->push_back(cont);
        cont += sampleSize;
    }
}

