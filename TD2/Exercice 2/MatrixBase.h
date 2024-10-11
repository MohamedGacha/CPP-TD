#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <vector>
#include <iostream>

template<typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T> > data; // 2D vector to store matrix data
    size_t rows;
    size_t cols;

public:
    // Constructor
    MatrixBase(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<T>(cols));
    }

    // Add an element to the matrix
    void addElement(size_t row, size_t col, const T& value) {
        if (row < rows && col < cols) {
            data[row][col] = value;
        }
    }

    // Get an element from the matrix
    T getElement(size_t row, size_t col) const {
        if (row < rows && col < cols) {
            return data[row][col];
        }
        throw std::out_of_range("Index out of range");
    }

    // Get number of rows
    size_t getRows() const {
        return rows;
    }

    // Get number of columns
    size_t getCols() const {
        return cols;
    }

    // Display the matrix
    void display() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif // MATRIXBASE_H
