//
// Created by Alberto Casas Ortiz.
//

#include "WriteResultsInFile.h"
#include "../../configuration/Configuration.h"
#include "../../problem/functions/Functions.h"
#include "../../qualitymeasures/QualityMeasures.h"

void WriteResultsInFile::writeResults(ExecutionData *data) {
    std::ofstream file;
    file.open (data->getName() + ".txt");

    file << "File: " << data->getName() << std::endl;
    file << std::endl;

    file << "//////CONFIGURATION//////" << std::endl;
    file << "Problem: " << Configuration::problemName << std::endl;
    file << "Selection Parents: " << Configuration::nameSelectionParents << std::endl;
    file << "Reproduction: " << Configuration::nameReproduction << std::endl;
    file << "Mutation: " << Configuration::nameMutation << std::endl;
    file << "Selection Survivors: " << Configuration::nameSelectionSurvivors << std::endl;
    file << "Num. Executions: " << Configuration::numExecutions << std::endl;
    file << "Population size: " << Configuration::populationSize << std::endl;
    file << "Offspring size: " << Configuration::offspringSize << std::endl;
    file << "Max. generations: " << Configuration::maxNumGenerations << std::endl;
    file << "Max. codon value: " << Configuration::maxCodonValue << std::endl;
    file << "Wrapping: " << Configuration::wrapping << std::endl;
    file << "Min. interval: " << Configuration::minInterval << std::endl;
    file << "Max. interval: " << Configuration::maxInterval << std::endl;
    file << "Samples: " << Configuration::samples << std::endl;
    file << "Function: " << Configuration::function << std::endl;
    file << "Max. chrom. size: " << Configuration::maxChromosomeSize << std::endl;
    file << "Prob. reproduction: " << Configuration::pRep << std::endl;
    file << "Prob. mutation: " << Configuration::pMut << std::endl;
    file << "Elitism: " << Configuration::elitism << std::endl;
    file << "Num. Elitism: " << Configuration::numElitism << std::endl;
    file << std::endl;

    file << "//////Best Individual//////" << std::endl;
    file << "Fitness: " << data->getPopulation()->getBestIndividual()->getFitness() << std::endl;
    file << "Probability: " << data->getPopulation()->getBestIndividual()->getProbability() << std::endl;
    file << "Accum. Probability: " << data->getPopulation()->getBestIndividual()->getAccumulatedProbability() << std::endl;
    file << "Age: " << data->getPopulation()->getBestIndividual()->getAge() << std::endl;
    file << "Expression: " << data->getPopulation()->getBestIndividual()->getExpression() << std::endl;
    file << "Genotype: ";
    for(int i : *data->getPopulation()->getBestIndividual()->getChromosome()){
        file << i << " ";
    }
    file << std::endl;
    file << std::endl;

    file << "//////Quality measures//////" << std::endl;
    file << "Execution time: " << std::to_string(QualityMeasures::time(data)) << std::endl;
    file << "Num. evaluations: " << std::to_string(QualityMeasures::numEvaluations(data)) << std::endl;
    file << "Success rate: " << std::to_string(QualityMeasures::successRate(data)) << std::endl;
    file << "Num. hits: " << std::to_string(QualityMeasures::numHits(data)) << std::endl;
    file << "Generations: " << std::to_string(data->getGenerations()) << std::endl;
    file << "Best fitness: " << std::to_string(QualityMeasures::bestFitness(data)) << std::endl;
    file << "Worst fitness: " << std::to_string(QualityMeasures::worstFitness(data)) << std::endl;

    file.close();

    std::ofstream file_csv;
    file_csv.open(data->getName() + ".csv");

    file_csv << "x" << ";" << "Expected" << ";" << "Result" << std::endl;
    for(int i = 0; i < Configuration::x->size(); i++){
        file_csv << Configuration::x->at(i) << ";"
             << Functions::executeFunction(Configuration::function)->at(i) << ";"
             << data->getPopulation()->getBestIndividual()->getFenotype()->at(i) << std::endl;
    }
    file_csv << std::endl;

    file_csv.close();
}
