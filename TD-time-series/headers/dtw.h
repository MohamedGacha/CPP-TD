#ifndef DTW_H
#define DTW_H

#include <vector>

// Function to calculate the Dynamic Time Warping (DTW) distance between two time series
double dtw_distance(const std::vector<double>& x, const std::vector<double>& y);

#endif // DTW_H
