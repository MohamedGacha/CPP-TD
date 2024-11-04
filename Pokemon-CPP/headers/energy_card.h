#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "card.h"

class EnergyCard : public Card {
private:
    std::string energyType;

public:
    EnergyCard(const std::string& type) : Card("Energy"), energyType(type) {}

    void displayInfo() const override {
        std::cout << "Energy Card - Name: " << cardName << ", Type: " << energyType << "\n";
    }

    std::string getEnergyType() const {
        return energyType;
    }
};

#endif // ENERGY_CARD_H
