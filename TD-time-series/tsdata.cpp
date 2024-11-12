#include "tsdata.h"
#include <cmath>
#include <algorithm>

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series) {
    // This version does not take a label
    data.push_back(series);
    maxLength = std::max(maxLength, static_cast<int>(series.size()));
    numberOfSamples++;
    if (znormalize) {
        std::vector<double> seriesCopy = series;
        zNormalize(seriesCopy); // Modify the copy for z-normalization
    }
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    // This version takes a label along with the series
    data.push_back(series);
    labels.push_back(label);
    maxLength = std::max(maxLength, static_cast<int>(series.size()));
    numberOfSamples++;
    if (znormalize) {
        std::vector<double> seriesCopy = series;
        zNormalize(seriesCopy); // Modify the copy for z-normalization
    }
}

std::vector<double> TimeSeriesDataset::zNormalize(const std::vector<double>& series) {
    double mean = 0.0;
    for (double value : series) {
        mean += value;
    }
    mean /= series.size();

    double variance = 0.0;
    for (double value : series) {
        variance += (value - mean) * (value - mean);
    }
    variance /= series.size();
    double stddev = std::sqrt(variance);

    std::vector<double> normalizedSeries;
    for (double value : series) {
        normalizedSeries.push_back((value - mean) / stddev);
    }

    return normalizedSeries;
}

std::vector<std::vector<double>>& TimeSeriesDataset::getData() {
    return data;
}

std::vector<int>& TimeSeriesDataset::getLabels() {
    return labels;
}
