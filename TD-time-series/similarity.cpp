#include "similarity.h"
#include <cmath>
#include <stdexcept>

double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y) {
    // Check if both time series have the same length
    if (x.size() != y.size()) {
        throw std::invalid_argument("The two time series must have the same length.");
    }

    double sum = 0.0;

    // Compute the squared differences for each pair of corresponding values
    for (size_t i = 0; i < x.size(); ++i) {
        double diff = x[i] - y[i];
        sum += diff * diff;  // Square the difference and accumulate
    }

    // Return the square root of the sum (standard Euclidean distance)
    return std::sqrt(sum);
}
