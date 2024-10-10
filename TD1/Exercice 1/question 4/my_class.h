#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <iostream>
#include <string>

class my_class {
private:
    std::string myString;  // Variable privée de type string

public:
    // Constructeur par défaut
    my_class();

    // Constructeur avec argument
    my_class(const std::string& str);

    // Fonction publique pour imprimer la variable privée
    void print_my_element() const;
};

#endif // MY_CLASS_H
