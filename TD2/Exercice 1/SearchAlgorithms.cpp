#include "SearchingAlgorithm.h"
#include <cmath>
#include <algorithm>

// Linear Search Algorithm
class LinearSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& vec, int target) override {
        numberComparisons = 0;
        for (size_t i = 0; i < vec.size(); ++i) {
            numberComparisons++;
            if (vec[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// Jump Search Algorithm
class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& vec, int target) override {
        numberComparisons = 0;
        size_t n = vec.size();
        size_t step = sqrt(n);
        size_t prev = 0;

        while (vec[std::min(step, n) - 1] < target) {
            numberComparisons++;
            prev = step;
            step += sqrt(n);
            if (prev >= n) {
                return -1;
            }
        }

        for (size_t i = prev; i < std::min(step, n); ++i) {
            numberComparisons++;
            if (vec[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// Binary Search Algorithm
class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& vec, int target) override {
        numberComparisons = 0;
        size_t low = 0;
        size_t high = vec.size() - 1;

        while (low <= high) {
            numberComparisons++;
            size_t mid = low + (high - low) / 2;

            if (vec[mid] == target) {
                return mid;
            }
            if (vec[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
