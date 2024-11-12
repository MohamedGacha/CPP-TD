#ifndef GAU_H
#define GAU_H

#include <vector>
#include <random>
#include <cmath>

class GaussianGenerator {
public:
    // Constructor with default values for mean and stddev
    GaussianGenerator(double mean = 0.0, double stddev = 1.0, int seed = 123)
        : mean(mean), stddev(stddev), seed(seed) {}

    // Method to generate a time series of Gaussian-distributed values
    std::vector<double> generateTimeSeries(int size);

private:
    double mean;    // Mean of the Gaussian distribution
    double stddev;  // Standard deviation of the Gaussian distribution
    int seed;       // Random seed for reproducibility
};

#endif // GAU_H
