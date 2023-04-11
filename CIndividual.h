#ifndef TEP_LISTA6_CINDIVIDUAL_H
#define TEP_LISTA6_CINDIVIDUAL_H

#include <vector>
#include "CKnapsackProblem.h"

class CIndividual {
public:
    CIndividual();
    CIndividual(const CIndividual& other);
    ~CIndividual();
    void calculateFitness(CKnapsackProblem& knapsackProblem);
    std::vector<CIndividual> cross(CIndividual& other);
    void mutateWithProb(float mutationProb);
    void generateRandomGenotype(int numberOfItems);
    void print();
    void setFitness(int value);
    int getFitness() const;
private:
    std::vector<bool> genotype;
    int fitness;
};


#endif //TEP_LISTA6_CINDIVIDUAL_H
