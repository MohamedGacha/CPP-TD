#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Fonction brute force : Complexité O(n^2)
vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // Si aucune solution n'est trouvée
}

// Fonction optimale : Complexité O(n)
vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Stocke les valeurs et leurs indices
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Indices de la paire trouvée
        }
        numMap[nums[i]] = i; // Stocke la valeur actuelle avec son indice
    }
    return {}; // Si aucune solution n'est trouvée
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Appel de la solution brute force
    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: [" << indicesBruteForce[0] << " , " << indicesBruteForce[1] << "]" << endl;

    // Appel de la solution optimale
    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: [" << indicesOptimal[0] << " , " << indicesOptimal[1] << "]" << endl;

    return 0;
}
