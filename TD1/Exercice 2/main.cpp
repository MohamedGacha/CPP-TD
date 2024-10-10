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


    Complex2D z1(1.0, 0.0);  // 1 + 0i

    // Rotation de z1 par un angle de 90 degrés (pi/2 radians)
    double theta = M_PI / 2;  // 90 degrés en radians
    Complex2D rotated_z1 = z1.rotate(theta);

    std::cout << "z1: " << z1 << std::endl;
    std::cout << "après rotaions de 90 degrés: " << rotated_z1 << std::endl;

     try {
        Complex2D z1_inverse = z1.inverse();
        std::cout << "Inverse of z1: " << z1_inverse << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
