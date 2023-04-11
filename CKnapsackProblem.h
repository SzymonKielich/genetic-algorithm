#ifndef TEP_LISTA6_CKNAPSACKPROBLEM_H
#define TEP_LISTA6_CKNAPSACKPROBLEM_H

#include <vector>
#include <string>

class CKnapsackProblem {
public:
    CKnapsackProblem();
    CKnapsackProblem(std::string filename);
    ~CKnapsackProblem();
    int getNumberOfItems();
    int getCapacity();
    const std::vector<int>& getSizes() const;
    const std::vector<int>& getValues() const;
private:
    int numberOfItems;
    std::vector<int> sizes;
    std::vector<int> values;
    int capacity;

};


#endif //TEP_LISTA6_CKNAPSACKPROBLEM_H
