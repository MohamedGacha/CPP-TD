#include "edit_distance.h"
#include <cmath>
#include <algorithm>
#include <limits>

// Function to calculate the Edit Distance between two real-valued sequences
double edit_distance(const std::vector<double>& x, const std::vector<double>& y) {
    int m = x.size();
    int n = y.size();

    // Create a matrix to store the edit distances
    std::vector<std::vector<double>> D(m + 1, std::vector<double>(n + 1, 0.0));

    // Initialize the first row and column of the matrix
    for (int i = 1; i <= m; ++i) {
        D[i][0] = D[i-1][0] + 1;  // Deletion
    }
    for (int j = 1; j <= n; ++j) {
        D[0][j] = D[0][j-1] + 1;  // Insertion
    }

    // Fill the matrix using dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Compute the cost of substitution (squared difference)
            double substitution_cost = std::pow(x[i - 1] - y[j - 1], 2);

            // Compute the minimum cost of insertion, deletion, or substitution
            D[i][j] = std::min({
                D[i-1][j] + 1,              // Deletion
                D[i][j-1] + 1,              // Insertion
                D[i-1][j-1] + substitution_cost // Substitution
            });
        }
    }

    // Return the final edit distance
    return D[m][n];
}
