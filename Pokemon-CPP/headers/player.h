#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "pokemon_card.h"
#include "trainer_card.h"
#include "energy_card.h"
#include <vector>
#include <iostream>

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;        // Cards on the bench
    std::vector<PokemonCard*> actionCards; // Active Pokemon cards

public:
    Player(const std::string& name) : playerName(name) {}

    void addCardToBench(Card* card) {
        benchCards.push_back(card);
    }

    void activatePokemonCard(int index) {
        if (index >= 0 && index < benchCards.size()) {
            PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
            if (pokemon) {
                actionCards.push_back(pokemon);
                benchCards.erase(benchCards.begin() + index); // Remove from bench
                std::cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << "\n";
            }
        }
    }

    void attachEnergyCard(int energyIndex, int actionCardIndex) {
        if (energyIndex >= 0 && energyIndex < benchCards.size() && actionCardIndex >= 0 && actionCardIndex < actionCards.size()) {
            EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
            if (energyCard) {
                std::cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType() 
                          << " to the Pokemon " << actionCards[actionCardIndex]->getCardName() << "\n";
            }
        }
    }

    void displayBench() const {
        std::cout << "Bench cards for Player " << playerName << ":\n";
        for (const auto& card : benchCards) {
            card->displayInfo();
        }
    }

    void displayAction() const {
        std::cout << "Action cards for Player " << playerName << ":\n";
        for (const auto& pokemon : actionCards) {
            pokemon->displayInfo();
        }
    }

    void attack(int actionCardIndex, int attackIndex, Player& opponent, int opponentActionIndex) {
        if (actionCardIndex >= 0 && actionCardIndex < actionCards.size() &&
            opponentActionIndex >= 0 && opponentActionIndex < opponent.actionCards.size()) {
            auto* attackingPokemon = actionCards[actionCardIndex];
            auto* defendingPokemon = opponent.actionCards[opponentActionIndex];
            int damage = attackingPokemon->performAttack(attackIndex);
            defendingPokemon->takeDamage(damage);
            std::cout << playerName << " attacking " << opponent.playerName << "'s Pokemon "
                      << defendingPokemon->getCardName() << " with " << attackingPokemon->getCardName()
                      << " using attack: " << attackIndex << "\n";
        }
    }

    void useTrainer(int index) {
        if (index >= 0 && index < benchCards.size()) {
            TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
            if (trainer) {
                trainer->useEffect(actionCards);
            }
        }
    }
};

#endif
