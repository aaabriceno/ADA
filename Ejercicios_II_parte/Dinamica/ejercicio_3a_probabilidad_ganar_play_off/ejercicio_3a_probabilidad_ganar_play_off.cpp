#include <iostream>
#include <vector>
using namespace std;

double calcularProbabilidad(int n, double P) {
    // Crear una matriz dp de tamaño (n+1) x (n+1)
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));

    // Caso base: Informáticos CB ya ganó
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1.0;
    }

    // Caso base: Basket Telecom ya ganó
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0.0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = P * dp[i - 1][j] + (1 - P) * dp[i][j - 1];
        }
    }

    return dp[n][n];
}

int main() {
    int n; double P;
    cout << "Numero de victorias necesarias para ganar el play-off (n): "; cin >> n;
    cout << "Probabilidad de que Informaticos CB gane un partido (P): "; cin >> P;

    double probabilidad = calcularProbabilidad(n, P);
    cout << "La probabilidad de que Informaticos CB gane el play-off es: " << probabilidad << endl;

    return 0;
}
