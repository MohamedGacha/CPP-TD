#ifndef KNN_H
#define KNN_H

#include "tsdata.h"
#include <string>
#include <vector>

class KNN {
private:
    int k;                    // Number of neighbors
    std::string similarity;   // Similarity measure ("euclidean_distance", "dtw", etc.)

public:
    KNN(int k, const std::string& similarity);

    double evaluate(TimeSeriesDataset& trainData, TimeSeriesDataset& testData);
    
    int predict(const std::vector<double>& testSeries, TimeSeriesDataset& trainData);
    double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y);
    double dtw_distance(const std::vector<double>& x, const std::vector<double>& y);
};

#endif // KNN_H
