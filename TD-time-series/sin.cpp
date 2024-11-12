#include "headers/sin.h"

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    series.reserve(size);

    for (int i = 0; i < size; ++i) {
        double x = static_cast<double>(i);
        double value = amplitude * std::sin(frequency * x + phase);
        series.push_back(value);
    }

    return series;
}
