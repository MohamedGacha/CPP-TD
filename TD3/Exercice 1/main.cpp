#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Fonction brute force
void countFrequencyBruteForce(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        int count = 0;
        // Compte le nombre de fois que numbers[i] apparaît dans le tableau
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                count++;
            }
        }
        // Affiche la fréquence seulement si cet élément n'a pas déjà été compté
        bool alreadyCounted = false;
        for (int k = 0; k < i; k++) {
            if (numbers[k] == numbers[i]) {
                alreadyCounted = true;
                break;
            }
        }
        if (!alreadyCounted) {
            cout << numbers[i] << ": " << count << " times" << endl;
        }
    }
}

// Fonction optimale avec une map
map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;
    // On parcourt le vecteur et on met à jour la fréquence de chaque élément dans la map
    for (int num : numbers) {
        frequencyMap[num]++;
    }
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce(numbers);

    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }

    return 0;
}
