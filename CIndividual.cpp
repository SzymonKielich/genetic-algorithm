#include <iostream>
#include "CIndividual.h"

CIndividual::CIndividual() {
    fitness=0;
}
CIndividual::CIndividual(const CIndividual& other) {

    fitness = other.fitness;
    genotype = other.genotype;
}

CIndividual::~CIndividual() {
    genotype.clear();
}

void CIndividual::calculateFitness(CKnapsackProblem &kProblem) {
    int totalValue=0;
    int totalWeight=0;
    const std::vector<int>& sizes = kProblem.getSizes();
    const std::vector<int>& values = kProblem.getValues();
    for(int i=0; i<genotype.size(); i++) {
        if(genotype[i]) {
            totalValue+=values[i];
            totalWeight+=sizes[i];
        }
    }
    if(totalWeight<=kProblem.getCapacity()) {
        fitness=totalValue;
    } else fitness = 0;

}

void CIndividual::mutateWithProb(float mutProb) {
    float random;
    for(int i=0; i<genotype.size(); i++) {
        random = (float)rand() / RAND_MAX;
        if(random <mutProb) genotype[i] = !genotype[i];
    }
}

std::vector<CIndividual> CIndividual::cross(CIndividual &other) {
    int divisionIndex = (rand() % (genotype.size()-1))+1;
    std::vector<CIndividual> childrenTuple(2);
    for(int i=0; i<genotype.size(); i++) {
        if(i<divisionIndex) {
            childrenTuple[0].genotype.push_back(genotype[i]);
            childrenTuple[1].genotype.push_back(other.genotype[i]);
        } else {
            childrenTuple[0].genotype.push_back(other.genotype[i]);
            childrenTuple[1].genotype.push_back(genotype[i]);
        }
    }

    return childrenTuple;
}

void CIndividual::generateRandomGenotype(int numberOfItems) {
    genotype.resize(numberOfItems);
    for(int i=0; i<numberOfItems; i++) {
        genotype[i]=rand()%2;
    }
}
void CIndividual::print() {
    std::cout<<"fitness: "<<fitness<<std::endl;
    for(int i=0; i<genotype.size(); i++) {
        std::cout<<genotype[i]<<std::endl;
    }
}

void CIndividual::setFitness(int value) {
    fitness = value;
}

int CIndividual::getFitness() const{
    return fitness;
}






