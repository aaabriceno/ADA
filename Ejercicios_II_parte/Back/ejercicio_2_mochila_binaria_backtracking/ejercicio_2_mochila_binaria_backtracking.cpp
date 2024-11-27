#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Backtracking para resolver la mochila
void knapsackBacktracking(const vector<int>& W, const vector<int>& B, int idx, int current_weight, int current_benefit, int& max_benefit, int capacity) {
    if (idx == W.size()) { // Caso base: se evaluaron todos los objetos
        max_benefit = max(max_benefit, current_benefit);
        return;
    }

    // Rama: incluir el objeto actual
    if (current_weight + W[idx] <= capacity) {
        knapsackBacktracking(W, B, idx + 1, current_weight + W[idx], current_benefit + B[idx], max_benefit, capacity);
    }

    // Rama: no incluir el objeto actual
    knapsackBacktracking(W, B, idx + 1, current_weight, current_benefit, max_benefit, capacity);
}

int main() {
    int M = 61; // Tamaño de la mochila
    vector<int> W = { 1, 11, 21, 23, 33 }; // Pesos
    vector<int> B = { 11, 21, 31, 33, 43 }; // Beneficios
    int n = W.size();

    int max_benefit = 0;
    knapsackBacktracking(W, B, 0, 0, 0, max_benefit, M);

    cout << "Maximo beneficio (Backtracking): " << max_benefit << endl;
    return 0;
}
