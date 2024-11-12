#ifndef STP_H
#define STP_H

#include <vector>

class StepGenerator {
public:
    // Default constructor
    StepGenerator() {
        amplitude = 1.0;
        step_size = 2.0;
    }

    // Constructor with parameters
    StepGenerator(double amplitude, double step_size) {
        this->amplitude = amplitude;
        this->step_size = step_size;
    }

    // Function to generate the time series
    std::vector<double> generateTimeSeries(int length) {
        std::vector<double> timeSeries;
        for (int i = 0; i < length; i++) {
            double value = (i < step_size) ? 0 : amplitude;
            timeSeries.push_back(value);
        }
        return timeSeries;
    }

private:
    double amplitude;
    double step_size;
};

#endif
