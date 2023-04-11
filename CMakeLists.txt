cmake_minimum_required(VERSION 3.23)
project(TEP_Lista6)

set(CMAKE_CXX_STANDARD 23)

add_executable(TEP_Lista6 main.cpp CIndividual.cpp CIndividual.h CGeneticAlgorithm.cpp CGeneticAlgorithm.h CKnapsackProblem.cpp CKnapsackProblem.h)
