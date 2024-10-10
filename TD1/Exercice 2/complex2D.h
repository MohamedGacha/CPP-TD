#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <iostream>

class Complex2D {
private:
    double real;
    double imaginary;

public:
    Complex2D();

    Complex2D(double r, double i);

    Complex2D(double value);

    Complex2D(const Complex2D& other);

    // Getters
    double getReal() const;
    double getImaginary() const;

    // Setters
    void setReal(double r);
    void setImaginary(double i);

    // Opérateur +
    Complex2D operator+(const Complex2D& other) const;

    // Opérateur -
    Complex2D operator-(const Complex2D& other) const;

    // Opérateur *
    Complex2D operator*(const Complex2D& other) const;

    // Opérateur /
    Complex2D operator/(const Complex2D& other) const;

    // Opérateur <
    bool operator<(const Complex2D& other) const;

    // Opérateur >
    bool operator>(const Complex2D& other) const;

    bool operator==(const Complex2D& other) const; 

    // Méthode pour calculer l'argument
    double argument() const;

    // Méthode pour le module du nombre complexe
    double modulus() const;

    // Méthode pour le conjugué du nombre complexe
    Complex2D conjugate() const;

    // Override de l'opérateur << pour l'affichage
    friend std::ostream& operator<<(std::ostream& os, const Complex2D& c);
};

#endif // COMPLEX2D_H
