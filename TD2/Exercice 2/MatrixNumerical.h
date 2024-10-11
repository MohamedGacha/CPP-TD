#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <vector>
#include <functional>
#include <stdexcept>

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    // Constructor
    MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}

    // Get determinant
    T getDeterminant() const;

    // Overload '+' operator
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;

    // Overload '-' operator
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;

    // Overload '*' operator
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;

    // Overload '/' operator: Matrix division (multiplication by inverse)
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;

    // Get inverse of the matrix
    MatrixNumerical<T> getInverse() const;

    // Static method to get identity matrix
    static MatrixNumerical<T> getIdentity(size_t size);

private:
    // Calculate determinant
    T calculateDeterminant(const std::vector<std::vector<T>>& matrix) const;

    // Perform matrix operation
    MatrixNumerical<T> performOperation(const MatrixNumerical<T>& other, 
                                        std::function<T(T, T)> op) const;

    // Get cofactor of a matrix
    MatrixNumerical<T> getCoFactor(size_t p, size_t q, size_t n) const;
};

// Calculate determinant using recursion (for square matrices)
template<typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols)
        throw std::invalid_argument("Determinant can only be calculated for square matrices");

    size_t n = this->rows;
    if (n == 1)
        return this->data[0][0];
    
    if (n == 2)
        return (this->data[0][0] * this->data[1][1]) - (this->data[0][1] * this->data[1][0]);

    T determinant = 0;
    int sign = 1;
    
    for (size_t i = 0; i < n; ++i) {
        MatrixNumerical<T> cofactorMatrix = getCoFactor(0, i, n);
        determinant += sign * this->data[0][i] * cofactorMatrix.getDeterminant();
        sign = -sign;
    }

    return determinant;
}

// Get cofactor of a matrix
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCoFactor(size_t p, size_t q, size_t n) const {
    MatrixNumerical<T> temp(n - 1, n - 1);
    size_t row = 0, col = 0;
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i != p && j != q) {
                temp.addElement(row, col++, this->data[i][j]);
                if (col == n - 1) {
                    col = 0;
                    row++;
                }
            }
        }
    }
    return temp;
}

// Operator +: Matrix addition
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols)
        throw std::invalid_argument("Matrix dimensions must agree for addition.");

    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            result.addElement(i, j, this->data[i][j] + other.data[i][j]);

    return result;
}

// Operator -: Matrix subtraction
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols)
        throw std::invalid_argument("Matrix dimensions must agree for subtraction.");

    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            result.addElement(i, j, this->data[i][j] - other.data[i][j]);

    return result;
}

// Operator *: Matrix multiplication
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& other) const {
    if (this->cols != other.rows)
        throw std::invalid_argument("Matrix dimensions must agree for multiplication.");

    MatrixNumerical<T> result(this->rows, other.cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            T sum = 0;
            for (size_t k = 0; k < this->cols; ++k)
                sum += this->data[i][k] * other.data[k][j];
            result.addElement(i, j, sum);
        }
    }

    return result;
}

// Operator /: Matrix division (multiplication by inverse)
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& other) const {
    MatrixNumerical<T> inverse = other.getInverse();
    return (*this) * inverse;
}

// Get inverse using cofactor method
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    if (this->rows != this->cols)
        throw std::invalid_argument("Inverse can only be calculated for square matrices");

    T det = getDeterminant();
    if (det == 0)
        throw std::invalid_argument("Matrix is singular, inverse does not exist.");

    size_t n = this->rows;
    MatrixNumerical<T> adjoint(n, n);

    int sign = 1;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            MatrixNumerical<T> cofactorMatrix = getCoFactor(i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjoint.addElement(j, i, sign * cofactorMatrix.getDeterminant());
        }
    }

    MatrixNumerical<T> inverse(n, n);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            inverse.addElement(i, j, adjoint.getElement(i, j) / det);

    return inverse;
}

// Static function to generate identity matrix
template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t size) {
    MatrixNumerical<T> identity(size, size);
    for (size_t i = 0; i < size; ++i)
        identity.addElement(i, i, 1);
    return identity;
}

#endif // MATRIXNUMERICAL_H
