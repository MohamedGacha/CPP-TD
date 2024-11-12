#ifndef TSDATA_H
#define TSDATA_H

#include <vector>

class TimeSeriesDataset {
public:
    TimeSeriesDataset(bool znormalize = false, bool isTrain = false);

    void addTimeSeries(const std::vector<double>& series); // For time series without labels
    void addTimeSeries(const std::vector<double>& series, int label); // For time series with labels

    std::vector<std::vector<double>>& getData();
    std::vector<int>& getLabels();

private:
    bool znormalize;
    bool isTrain;
    int maxLength;
    int numberOfSamples;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;

    // zNormalization function
    std::vector<double> zNormalize(const std::vector<double>& series);
};

#endif // TSDATA_H
