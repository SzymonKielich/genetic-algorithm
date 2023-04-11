#include <iostream>
#include "CGeneticAlgorithm.h"

int main() {

    srand(time(NULL));
    CGeneticAlgorithm cgen(1000, 0.5, 0.5);
    CKnapsackProblem cknap("C:\\Users\\szymo\\CLionProjects\\TEP_Lista6\\f4_l-d_kp_4_11"); // optimal: 23
    CKnapsackProblem cknap2("C:\\Users\\szymo\\CLionProjects\\TEP_Lista6\\f8_l-d_kp_23_10000"); // optimal: 9767
    CKnapsackProblem cknap3("C:\\Users\\szymo\\CLionProjects\\TEP_Lista6\\f10_l-d_kp_20_879"); // optimal: 1025


    cgen.start(15, cknap);
    cgen.start(50, cknap2);
    cgen.start(50, cknap3);

    return 0;
}
