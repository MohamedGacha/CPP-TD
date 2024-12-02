#include "headers/gau.h"

// Box-Muller method to generate Gaussian-distributed values
std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    series.reserve(size);

    std::mt19937 rng(seed);              // Mersenne Twister RNG, seeded
    std::uniform_real_distribution<> dist(0.0, 1.0);  // Uniform distribution for [0, 1)

    for (int i = 0; i < size; i += 2) {
        // Generate two uniform random numbers
        double u1 = dist(rng);
        double u2 = dist(rng);

        // Box-Muller transform
        double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2 * M_PI * u2);
        double z1 = std::sqrt(-2.0 * std::log(u1)) * std::sin(2 * M_PI * u2);

        // Scale by mean and stddev, add to the series
        series.push_back(mean + z0 * stddev);
        if (i + 1 < size) {
            series.push_back(mean + z1 * stddev);
        }
    }

    return series;
}
