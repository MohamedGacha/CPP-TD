#include "headers/TimeSeriesGenerator.h"

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int seedValue) : seed(seedValue) {}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    for (double value : series) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
