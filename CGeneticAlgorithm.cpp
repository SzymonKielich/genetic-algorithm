#include <stdexcept>
#include <iostream>
#include "CGeneticAlgorithm.h"
CGeneticAlgorithm::CGeneticAlgorithm() {
    popSize = 2;
    crossProb = 0.5;
    mutProb = 0.5;

}

CGeneticAlgorithm::CGeneticAlgorithm(int population, float crossProbability, float mutProbability) {
    if(population>=2) {
        popSize = population;
    } else popSize=2;

    crossProb = crossProbability;
    mutProb = mutProbability;
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    population.clear();
}
CIndividual& CGeneticAlgorithm::start(int iterNum, CKnapsackProblem &kProblem) {
    bestIndividual.setFitness(0);
    population.clear();
    generateRandomPopulation(kProblem);
    calculateValues(kProblem);
    for(int i=0; i<iterNum; i++) {
        crossPopulation();
        mutatePopulation();
        calculateValues(kProblem);
    }
    std::cout<<"Best solution: " <<bestIndividual.getFitness()<<std::endl;
    return bestIndividual;

}

void CGeneticAlgorithm::generateRandomPopulation(CKnapsackProblem &kProblem) {
    population.resize(popSize);
    for(int i=0; i<popSize; i++) {
        population[i].generateRandomGenotype(kProblem.getNumberOfItems());
    }
}

void CGeneticAlgorithm::calculateValues(CKnapsackProblem &kProblem) {
    for(int i=0; i<popSize; i++) {
        population[i].calculateFitness(kProblem);
        if(population[i].getFitness()>bestIndividual.getFitness()) {
            bestIndividual = population[i];
        }
    }
}

void CGeneticAlgorithm::crossPopulation() {

    std::vector<CIndividual> allNewChildren(popSize);
    std::vector<CIndividual> twoChildren(2);
    int parentInd1, parentInd2;

    for(int i=0; i<popSize; i++) {
        //nieparzysta populacja
        if(i==popSize-1) {
            allNewChildren[i]=population[findBetterInd()];
        } else {
            parentInd1 = findBetterInd();
            parentInd2 = findBetterInd();
            while(parentInd1==parentInd2) {
                parentInd2 = findBetterInd();
            }
            //zachodzi krzyzowanie
            if((float)rand() / RAND_MAX <= crossProb) {
                twoChildren = population[parentInd1].cross(population[parentInd2]);
                allNewChildren[i] = twoChildren[0];
                i++;
                allNewChildren[i] = twoChildren[1];
            } else {
                allNewChildren[i] = population[parentInd1];
                i++;
                allNewChildren[i] = population[parentInd2];
            }
        }
    }
    population = allNewChildren;
}

void CGeneticAlgorithm::mutatePopulation() {
    for(int i=0; i<popSize; i++) {
        population[i].mutateWithProb(mutProb);
    }
}

int CGeneticAlgorithm::findBetterInd() {
    int index1 = rand()%popSize;
    int index2 = rand()%popSize;
    return (population[index1].getFitness()>population[index2].getFitness()) ? index1 : index2;
}
void CGeneticAlgorithm::printPopulation() {
    std::cout<<"Printing population: "<<std::endl;
    for(int i=0; i<popSize; i++) {
        population[i].print();
    }
}
// ------------- GETTERS & SETTERS ------------------

float CGeneticAlgorithm::getCrossProb() const {
    return crossProb;
}

void CGeneticAlgorithm::setCrossProb(float crossProb) {
    crossProb = crossProb;
}

float CGeneticAlgorithm::getMutProb() const {
    return mutProb;
}

void CGeneticAlgorithm::setMutProb(float mutProb) {
    mutProb = mutProb;
}





