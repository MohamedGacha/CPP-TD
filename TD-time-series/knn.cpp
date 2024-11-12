#include "headers/knn.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

KNN::KNN(int k, const std::string& similarity) : k(k), similarity(similarity) {}

double KNN::euclidean_distance(const std::vector<double>& x, const std::vector<double>& y) {
    double sum = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        sum += std::pow(x[i] - y[i], 2);
    }
    return std::sqrt(sum);
}

double KNN::dtw_distance(const std::vector<double>& x, const std::vector<double>& y) {
    size_t lenX = x.size();
    size_t lenY = y.size();
    std::vector<std::vector<double>> D(lenX + 1, std::vector<double>(lenY + 1, 0));

    D[0][0] = 0;
    for (size_t i = 1; i <= lenX; ++i) D[i][0] = std::numeric_limits<double>::infinity();
    for (size_t j = 1; j <= lenY; ++j) D[0][j] = std::numeric_limits<double>::infinity();

    for (size_t i = 1; i <= lenX; ++i) {
        for (size_t j = 1; j <= lenY; ++j) {
            double dist = std::pow(x[i - 1] - y[j - 1], 2);
            D[i][j] = dist + std::min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]});
        }
    }

    return std::sqrt(D[lenX][lenY]);
}

int KNN::predict(const std::vector<double>& testSeries, TimeSeriesDataset& trainData) {
    std::vector<std::pair<double, int>> distances; // Pair of distance and label

    for (size_t i = 0; i < trainData.getData().size(); ++i) {
        double dist = (similarity == "euclidean_distance") 
            ? euclidean_distance(testSeries, trainData.getData()[i])
            : dtw_distance(testSeries, trainData.getData()[i]);

        distances.push_back({dist, trainData.getLabels()[i]});
    }

    std::sort(distances.begin(), distances.end(), [](const std::pair<double, int>& a, const std::pair<double, int>& b) {
        return a.first < b.first;
    });

    std::map<int, int> count;
    for (int i = 0; i < k; ++i) {
        count[distances[i].second]++;
    }

    return std::max_element(count.begin(), count.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    })->first;
}

double KNN::evaluate(TimeSeriesDataset& trainData, TimeSeriesDataset& testData) {
    int correct = 0;
    const auto& testLabels = testData.getLabels();
    const auto& testSeries = testData.getData();

    for (size_t i = 0; i < testSeries.size(); ++i) {
        int predicted = predict(testSeries[i], trainData);
        if (predicted == testLabels[i]) {
            correct++;
        }
    }

    return static_cast<double>(correct) / testSeries.size();
}
