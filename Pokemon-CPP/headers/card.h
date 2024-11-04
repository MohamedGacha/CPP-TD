#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
protected:
    std::string cardName; // Name of the card

public:
    Card(const std::string& name) : cardName(name) {}
    virtual ~Card() {} // Virtual destructor

    virtual void displayInfo() const = 0; // Pure virtual function
};

#endif // CARD_H
