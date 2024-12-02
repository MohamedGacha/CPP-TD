#include "headers/dtw.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <iostream>

// Function to calculate the Dynamic Time Warping (DTW) distance between two time series
double dtw_distance(const std::vector<double>& x, const std::vector<double>& y) {
    int L = x.size();
    if (L != y.size()) {
        throw std::invalid_argument("The two time series must have the same length.");
    }

    // Create a matrix to store the DTW distances
    std::vector<std::vector<double>> D(L + 1, std::vector<double>(L + 1, std::numeric_limits<double>::infinity()));

    // Initialize the start point
    D[0][0] = 0;

    // Fill the matrix using dynamic programming
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= L; ++j) {
            // Calculate squared difference between x[i-1] and y[j-1]
            double d = std::pow(x[i - 1] - y[j - 1], 2);

            // Update the DTW matrix with the minimum cumulative distance
            D[i][j] = d + std::min({D[i - 1][j],    // Deletion
                                     D[i][j - 1],    // Insertion
                                     D[i - 1][j - 1]}); // Move
        }
    }

    // Return the DTW distance
    return std::sqrt(D[L][L]);
}
