#include "headers/stp.h"

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    series.reserve(size);

    std::mt19937 rng(seed);                       // Mersenne Twister RNG, seeded
    std::uniform_int_distribution<> valueDist(0, 100);  // Uniform distribution for values between 0 and 100
    std::bernoulli_distribution probDist(0.5);    // 50% probability for keeping the previous value

    double currentValue = 0;  // Start with the initial value of 0
    series.push_back(currentValue);

    for (int i = 1; i < size; ++i) {
        if (probDist(rng)) {
            // Keep the previous value
            series.push_back(currentValue);
        } else {
            // Generate a new random value between 0 and 100
            currentValue = valueDist(rng);
            series.push_back(currentValue);
        }
    }

    return series;
}
