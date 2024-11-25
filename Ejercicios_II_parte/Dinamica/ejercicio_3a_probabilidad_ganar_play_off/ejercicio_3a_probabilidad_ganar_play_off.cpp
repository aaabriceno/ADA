#include <iostream>
#include <vector>
using namespace std;

// Función que calcula la probabilidad de que el primer equipo gane el play-off
double calcularProbabilidad(int n, double P) {
    // Crear una matriz dp de tamaño (n+1) x (n+1)
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));

    // Caso base: Si el primer equipo no necesita más victorias, ya ha ganado
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1.0;  // El primer equipo ya ganó
    }

    // Caso base: Si el segundo equipo no necesita más victorias, ya ha ganado
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0.0;  // El primer equipo perdió
    }

    // Calcular las probabilidades para los casos generales
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = P * dp[i - 1][j] + (1 - P) * dp[i][j - 1];
        }
    }

    // La probabilidad de que el primer equipo gane el play-off cuando necesita n victorias y el segundo equipo necesita n victorias
    return dp[n][n];
}

int main() {
    int n;
    double P;

    // Solicitar entrada al usuario
    cout << "Numero de victorias necesarias para ganar el play-off (n): ";
    cin >> n;
    cout << "Probabilidad de que Informaticos CB gane un partido (P): ";
    cin >> P;

    // Calcular la probabilidad
    double probabilidad = calcularProbabilidad(n, P);

    // Mostrar el resultado
    cout << "La probabilidad de que Informaticos CB gane el play-off es: " << probabilidad << endl;

    return 0;
}
