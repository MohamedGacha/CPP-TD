#include "complex2D.h"
#include <cmath>

// default
Complex2D::Complex2D() : real(0), imaginary(0) {}

// 2 args
Complex2D::Complex2D(double r, double i) : real(r), imaginary(i) {}

// 1 arg
Complex2D::Complex2D(double value) : real(value), imaginary(value) {}

// copy
Complex2D::Complex2D(const Complex2D& other) : real(other.real), imaginary(other.imaginary) {}

// Getters
double Complex2D::getReal() const {
    return real;
}

double Complex2D::getImaginary() const {
    return imaginary;
}

// Setters
void Complex2D::setReal(double r) {
    real = r;
}

void Complex2D::setImaginary(double i) {
    imaginary = i;
}

// Opérateur +
Complex2D Complex2D::operator+(const Complex2D& other) const {
    return Complex2D(real + other.real, imaginary + other.imaginary);
}

// Opérateur -
Complex2D Complex2D::operator-(const Complex2D& other) const {
    return Complex2D(real - other.real, imaginary - other.imaginary);
}

// Opérateur *
Complex2D Complex2D::operator*(const Complex2D& other) const {
    return Complex2D(
        real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real
    );
}

// Opérateur /
Complex2D Complex2D::operator/(const Complex2D& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    return Complex2D(
        (real * other.real + imaginary * other.imaginary) / denominator,
        (imaginary * other.real - real * other.imaginary) / denominator
    );
}

// Opérateur <
bool Complex2D::operator<(const Complex2D& other) const {
    return this->modulus() < other.modulus();
}

// Opérateur >
bool Complex2D::operator>(const Complex2D& other) const {
    return this->modulus() > other.modulus();
}

// Opérateur ==
bool Complex2D::operator==(const Complex2D& other) const {
    return real == other.real && imaginary == other.imaginary;
}

// Méthode pour calculer l'argument
double Complex2D::argument() const {
    return std::atan2(imaginary, real);
}

// Calcul du module du nombre complexe
double Complex2D::modulus() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

// Calcul du conjugué
Complex2D Complex2D::conjugate() const {
    return Complex2D(real, -imaginary);
}

Complex2D Complex2D::rotate(double theta) const {
    // Calculer cos(theta) et sin(theta)
    double cos_theta = std::cos(theta);
    double sin_theta = std::sin(theta);

    // Multiplier le nombre complexe par cos(theta) + i*sin(theta)
    double new_real = real * cos_theta - imaginary * sin_theta;
    double new_imag = real * sin_theta + imaginary * cos_theta;

    // Retourner le nombre complexe après rotation
    return Complex2D(new_real, new_imag);
}

// Override de l'opérateur << pour l'affichage
std::ostream& operator<<(std::ostream& os, const Complex2D& c) {
    os << c.real << " + " << c.imaginary << "i";
    return os;
}
