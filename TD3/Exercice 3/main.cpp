#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
    queue<char> q;
    stack<char> s;
    
    // On filtre les caractères alphanumériques et on les met en minuscule
    for (char c : input) {
        if (isalnum(c)) {
            char lowercaseChar = tolower(c);
            q.push(lowercaseChar); // Ajout à la file (pour l'ordre normal)
            s.push(lowercaseChar); // Ajout à la pile (pour l'ordre inversé)
        }
    }
    
    // On compare les éléments de la pile et de la file
    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false; // Si un caractère ne correspond pas, ce n'est pas un palindrome
        }
        q.pop(); // On retire de la file
        s.pop(); // On retire de la pile
    }

    return true; // Tous les caractères correspondent, c'est un palindrome
}

int main() {
    cout << boolalpha; // Pour afficher les booléens sous forme "true" ou "false"
    
    cout << "Is 'racecar' a palindrome? " << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? " << isPalindrome("hello") << endl;
    cout << "Is 'A man, a plan, a canal: Panama' a palindrome? " << isPalindrome("A man, a plan, a canal: Panama") << endl;

    return 0;
}
