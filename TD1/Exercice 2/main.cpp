#include "complex2D.h"
#include <iostream>

int main() {
    // Création de nombres complexes
    Complex2D c1(3.0, 4.0);     // 3 + 4i
    Complex2D c2(1.0, 2.0);    

    // Opérations arithmétiques
    Complex2D sum = c1 + c2;    // Addition
    Complex2D diff = c1 - c2;   // Soustraction
    Complex2D prod = c1 * c2;   // Multiplication
    Complex2D quot = c1 / c2;   // Division

    // Comparaison
    bool isLess = c1 < c2;
    bool isGreater = c1 > c2;

    // Affichage
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "Somme: " << sum << std::endl;
    std::cout << "Différence: " << diff << std::endl;
    std::cout << "Produit: " << prod << std::endl;
    std::cout << "Quotient: " << quot << std::endl;
    std::cout << "c1 < c2 ? " << (isLess ? "Oui" : "Non") << std::endl;
    std::cout << "c1 > c2 ? " << (isGreater ? "Oui" : "Non") << std::endl;

    std::cout << "Argument of c1: " << c1.argument() << " rad" << std::endl;

    if (c1 == c2) {
        std::cout << "c1 and c2 are equal" << std::endl;
    } else {
        std::cout << "c1 and c2 are not equal" << std::endl;
    }

    return 0;
}
