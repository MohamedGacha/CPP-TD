#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <vector>
#include <iostream>

class SearchingAlgorithm {
protected:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;

public:
    SearchingAlgorithm() : numberComparisons(0) {}

    virtual int search(const std::vector<int>& vec, int target) = 0;

    virtual void displaySearchResults(std::ostream& os, int result, int target) {
        totalComparisons += numberComparisons;
        totalSearch++;
        double averageComparisons = (double)totalComparisons / totalSearch;

        os << "Target: " << target << ", Result Index: " << result
           << ", Comparisons: " << numberComparisons << '\n'
           << "Total Comparisons: " << totalComparisons
           << ", Average Comparisons: " << averageComparisons << '\n';
    }

    static double getAverageComparisons() {
        return totalSearch == 0 ? 0 : (double)totalComparisons / totalSearch;
    }
};

// Static member initialization
int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;

#endif // SEARCHINGALGORITHM_H
