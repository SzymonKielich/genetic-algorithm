#ifndef TEP_LISTA6_CGENETICALGORITHM_H
#define TEP_LISTA6_CGENETICALGORITHM_H


#include "CIndividual.h"

class CGeneticAlgorithm {

public:
    CGeneticAlgorithm();
    CGeneticAlgorithm(int population, float crossProbability, float mutProbability);
    ~CGeneticAlgorithm();
    CIndividual& start(int iterNum, CKnapsackProblem& knapsackProblem);
    void generateRandomPopulation(CKnapsackProblem &knapsackProblem);
    void calculateValues(CKnapsackProblem &kProblem);
    void crossPopulation();
    void mutatePopulation();
    int findBetterInd();
    void printPopulation();
    // ------------- GETTERS & SETTERS ------------------
    float getCrossProb() const;
    void setCrossProb(float crossProb);
    float getMutProb() const;
    void setMutProb(float mutProb);


private:
    int popSize;
    float crossProb;
    float mutProb;
    std::vector<CIndividual> population;
    CIndividual bestIndividual;

};


#endif //TEP_LISTA6_CGENETICALGORITHM_H
