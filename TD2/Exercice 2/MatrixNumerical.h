#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    // Constructor
    MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}

    // Get determinant
    T getDeterminant() const {
        return calculateDeterminant(this->data);
    }

    // Overload '+' operator
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const {
        return performOperation(other, [](T a, T b) { return a + b; });
    }

    // Overload '-' operator
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const {
        return performOperation(other, [](T a, T b) { return a - b; });
    }

    // Overload '*' operator
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const {
        if (this->cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication");
        }
        MatrixNumerical<T> result(this->rows, other.cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                T sum = 0;
                for (size_t k = 0; k < this->cols; ++k) {
                    sum += this->data[i][k] * other.data[k][j];
                }
                result.addElement(i, j, sum);
            }
        }
        return result;
    }

    // Get inverse of the matrix
    MatrixNumerical<T> getInverse() const {
        // Implement Gauss-Jordan elimination or another method to find the inverse.
        // For simplicity, this is left unimplemented.
        // This function can call a helper function getCoFactor
    }

    // Static method to get identity matrix
    static MatrixNumerical<T> getIdentity(int size) {
        MatrixNumerical<T> identity(size, size);
        for (int i = 0; i < size; ++i) {
            identity.addElement(i, i, 1);
        }
        return identity;
    }

private:
    // Calculate determinant
    T calculateDeterminant(const std::vector<std::vector<T>>& matrix) const {
        // Determinant calculation logic goes here...
        return 0; // Placeholder
    }

    // Perform matrix operation
    MatrixNumerical<T> performOperation(const MatrixNumerical<T>& other, 
                                        std::function<T(T, T)> op) const {
        if (this->rows != other.rows || this->cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions do not match");
        }
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                result.addElement(i, j, op(this->getElement(i, j), other.getElement(i, j)));
            }
        }
        return result;
    }
};

#endif // MATRIXNUMERICAL_H
