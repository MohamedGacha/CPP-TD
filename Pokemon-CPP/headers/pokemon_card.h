#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple> 
#include "card.h"

class PokemonCard : public Card {
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp; // Current HP
    std::vector<std::tuple<int, int, std::string, int>> attacks; // cost, current cost, description, damage

public:
    // Constructor
    PokemonCard(const std::string& name, const std::string& type, const std::string& family, 
                int level, int maxHP, int currentHP, const std::string& attack1Desc, 
                int attack1Cost, int attack1Current, const std::string& attack2Desc, 
                int attack2Cost)
        : Card(name), pokemonType(type), familyName(family), evolutionLevel(level), 
          maxHP(maxHP), hp(currentHP) {
        attacks.push_back(std::make_tuple(attack1Cost, attack1Current, attack1Desc, 20)); // Attack 1
        attacks.push_back(std::make_tuple(attack2Cost, attack2Cost, attack2Desc, 30)); // Attack 2
    }

    // Getters
    int getCurrentHP() const { return hp; }
    std::string getCardName() const { return cardName; }

    // Damage function
    void takeDamage(int damage) {
        hp -= damage; // Reduce HP by damage
        if (hp < 0) hp = 0; // Ensure HP doesn't go below 0
    }

    void displayInfo() const override {
        std::cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
                  << ", Evolution Level: " << evolutionLevel << " of the family " << familyName
                  << ", HP: " << hp << "\n";

        std::cout << "Attacks:\n";
        for (size_t i = 0; i < attacks.size(); ++i) {
            std::cout << "  Attack #" << i << ":\n";
            std::cout << "    Attack cost: " << std::get<0>(attacks[i]) << "\n";
            std::cout << "    Attack current energy storage: " << std::get<1>(attacks[i]) << "\n";
            std::cout << "    Attack description: " << std::get<2>(attacks[i]) << "\n";
            std::cout << "    Attack damage: " << std::get<3>(attacks[i]) << "\n";
        }
    }

    int performAttack(int index) {
        if (index < 0 || index >= attacks.size()) {
            std::cerr << "Invalid attack index.\n";
            return 0; // Handle invalid index
        }
        return std::get<3>(attacks[index]); // Return damage
    }
    
    // Other member functions and attributes
};

#endif // POKEMON_CARD_H
