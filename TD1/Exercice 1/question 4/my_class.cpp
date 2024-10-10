#include "my_class.h"

// Constructeur par défaut
my_class::my_class() : myString("Default String") {}

// Constructeur avec un argument string
my_class::my_class(const std::string& str) : myString(str) {}

// Fonction pour imprimer la variable privée
void my_class::print_my_element() const {
    std::cout << myString << std::endl;
}
