#ifndef SIN_H
#define SIN_H

#include <vector>
#include <cmath>

class SinWaveGenerator {
public:
    // Default constructor
    SinWaveGenerator() {
        amplitude = 1.0;
        frequency = 1.0;
    }

    // Constructor with parameters
    SinWaveGenerator(double amplitude, double frequency) {
        this->amplitude = amplitude;
        this->frequency = frequency;
    }

    // Function to generate the time series
    std::vector<double> generateTimeSeries(int length) {
        std::vector<double> timeSeries;
        for (int i = 0; i < length; i++) {
            double value = amplitude * sin(frequency * i);
            timeSeries.push_back(value);
        }
        return timeSeries;
    }

private:
    double amplitude;
    double frequency;
};

#endif
