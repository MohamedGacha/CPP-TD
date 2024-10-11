#include "SearchingAlgorithm.h"
#include "SearchAlgorithms.cpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    // Linear Search
    LinearSearch linearSearch;
    int linearResult = linearSearch.search(vec, target);
    linearSearch.displaySearchResults(std::cout, linearResult, target);

    // Jump Search
    JumpSearch jumpSearch;
    int jumpResult = jumpSearch.search(vec, target);
    jumpSearch.displaySearchResults(std::cout, jumpResult, target);

    // Binary Search
    BinarySearch binarySearch;
    int binaryResult = binarySearch.search(vec, target);
    binarySearch.displaySearchResults(std::cout, binaryResult, target);

    return 0;
}