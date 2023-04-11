#include <fstream>
#include <iostream>
#include "CKnapsackProblem.h"
CKnapsackProblem::CKnapsackProblem() {
    numberOfItems=0;
    capacity=0;
}
//n wmax
//v1 w1
//v2 w2
//: :
CKnapsackProblem::CKnapsackProblem(std::string filename) {
    std::ifstream file(filename);
    if(file.is_open()) {
        int numItems=0, maxCapacity=0;
        file >> numItems >> maxCapacity;

        if(numItems > 0 && maxCapacity > 0) {
            numberOfItems = numItems;
            capacity = maxCapacity;
        } else {
            file.close();
            throw std::invalid_argument("Invalid/Negative number of items or capacity");
        }

        int value=0, size=0;
        while(file>>value>>size) {
            if(value>0 && size>0) {
                values.push_back(value);
                sizes.push_back(size);

            } else {
                file.close();
                throw std::invalid_argument("Negative weight or value");
            }
        }
        file.close();
        if(values.size()!=numberOfItems || sizes.size()!=numberOfItems) throw std::invalid_argument("Invalid file content");

    } else throw std::invalid_argument("File not found.");
}

CKnapsackProblem::~CKnapsackProblem() {
    sizes.clear();
    values.clear();
}


int CKnapsackProblem::getNumberOfItems() {
    return numberOfItems;
}

int CKnapsackProblem::getCapacity() {
    return capacity;
}

const std::vector<int>& CKnapsackProblem::getSizes() const {
    return sizes;
}

const std::vector<int>& CKnapsackProblem::getValues() const {
    return values;
}






