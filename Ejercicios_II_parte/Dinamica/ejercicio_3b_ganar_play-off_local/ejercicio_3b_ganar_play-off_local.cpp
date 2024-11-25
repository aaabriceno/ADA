#include <iostream>
#include <vector>
using namespace std;

double calcularProbabilidad(int n, double PL) {
    double PV = 1.0 - PL; // Probabilidad de ganar como visitante

    // Crear tabla DP: dp[i][j] representa la probabilidad de que Informáticos CB gane con i victorias restantes y Basket Telecom con j victorias restantes
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));

    // Casos base:
    // Si Informáticos CB gana todas las partidas que necesita antes que Basket Telecom
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1.0; // Informáticos CB ya ganó
    }
    // Si Basket Telecom gana todas las partidas que necesita antes que Informáticos CB
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0.0; // Basket Telecom ya ganó
    }

    // Rellenar la tabla DP de abajo hacia arriba
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = PL * dp[i - 1][j] + PV * dp[i][j - 1];
        }
    }

    // Retornar la probabilidad final
    return dp[n][n];
}

int main() {
    int n = 3;       // Número de victorias necesarias
    double PL = 0.6; // Probabilidad de ganar como local (PL > PV)
    cout << "Ingrese el numero de victorias necesarias: "; cin >> n;
	cout << "Ingrese la probabilidad de ganar de Local: "; cin >> PL;
    if (PL <= 0.5) {
        cout << "Error: PL debe ser mayor que 0.5, ya que PL > PV (ventaja de campo).\n";
        return 1;
    }

    double probabilidadGanar = calcularProbabilidad(n, PL);

    cout << "La probabilidad de que Informaticos CB gane el play-off es: " << probabilidadGanar << endl;

    return 0;
}
