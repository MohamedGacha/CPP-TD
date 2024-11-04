#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include "card.h"
#include "pokemon_card.h"

class TrainerCard : public Card {
private:
    std::string trainerEffect;

public:
    TrainerCard(const std::string& name, const std::string& effect)
        : Card(name), trainerEffect(effect) {}

    void displayInfo() const override {
        std::cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << "\n";
    }

    void useEffect(std::vector<PokemonCard*>& actionCards) {
        for (auto* pokemon : actionCards) {
            if (pokemon) {
                pokemon->takeDamage(- (pokemon->getCurrentHP() - pokemon->getCurrentHP())); // Heal to max HP
            }
        }
        std::cout << cardName << " is used: " << trainerEffect << "\n";
    }
};

#endif
