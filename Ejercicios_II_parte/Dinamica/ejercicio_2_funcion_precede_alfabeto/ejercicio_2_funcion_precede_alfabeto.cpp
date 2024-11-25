#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool f(char x, char y) {
    unordered_map<char, int> order = { {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4} };
    return order[x] + 1 == order[y];
}

bool precede(char u, char v, const vector<char>& sigma) {
    int n = sigma.size();

    unordered_map<char, unordered_map<char, bool>> dp;
    for (char x : sigma) {
        for (char y : sigma) {
            dp[x][y] = f(x, y);  // Inicialización según la relación inmediata
        }
    }
    for (char z : sigma) {           // Elemento intermedio
        for (char x : sigma) {       // Elemento inicial
            for (char y : sigma) {   // Elemento final
                dp[x][y] = dp[x][y] || (dp[x][z] && dp[z][y]);
            }
        }
    }

    return dp[u][v];
}

int main() {
    vector<char> sigma = { 'a', 'b', 'c', 'd' };  // Alfabeto
    char u = 'a', v = 'b';                      // Elementos a verificar

    // Determinar si u precede a v
    if (precede(u, v, sigma)) {
        cout << u << " precede a " << v << " en el orden total." << endl;
    }
    else {
        cout << u << " no precede a " << v << " en el orden total." << endl;
    }

    return 0;
}
