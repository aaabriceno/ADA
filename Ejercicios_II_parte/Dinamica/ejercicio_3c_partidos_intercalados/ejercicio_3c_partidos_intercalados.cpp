#include <iostream>
#include <vector>
using namespace std;

// Función para calcular la probabilidad usando programación dinámica
double calcularProbabilidad(int n, double PL, double PV) {
    // Crear una tabla dp de tamaño (n+1) x (n+1), inicializada a 0.0
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));

    // Caso base: Si el primer equipo ya ha ganado (i == 0), la probabilidad es 1
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1.0;
    }

    // Caso base: Si el segundo equipo ya ha ganado (j == 0), la probabilidad es 0
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0.0;
    }

    // Llenado de la tabla dp utilizando programación dinámica
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Alternamos entre jugar en casa (PL) y jugar fuera (PV) dependiendo del partido
            if ((i + j) % 2 == 0) {  // Si el partido es en casa
                dp[i][j] = PL * dp[i - 1][j] + (1.0 - PV) * dp[i][j - 1];
            }
            else {  // Si el partido es fuera
                dp[i][j] = PV * dp[i - 1][j] + (1.0 - PL) * dp[i][j - 1];
            }
        }
    }

    // La probabilidad de que el primer equipo gane el play-off es dp[n][n]
    return dp[n][n];
}

int main() {
    int n;
    double PL, PV;

    cout << "Numero de victorias necesarias para ganar el play-off (n): ";
    cin >> n;

    // Pedir al usuario que ingrese las probabilidades hasta que PL sea mayor que PV
    do {
        cout << "Probabilidad de que el primer equipo gane como local (PL): ";
        cin >> PL;

        if (PL >= 1.0) {
            cout << "PL no puede ser mayor o igual a 1.0. Ingrese nuevamente: ";
            continue;
        }

        // Definir PV como 1 - PL
        PV = 1 - PL;

        // Restricción: PL debe ser mayor que PV
        if (PL <= PV) {
            cout << "PL debe ser mayor que PV. Ingrese nuevamente." << endl;
        }
    } while (PL <= PV); // El bucle sigue pidiendo si PL <= PV

    // Calcular la probabilidad de que el primer equipo gane el play-off
    double probabilidad = calcularProbabilidad(n, PL, PV);

    cout << "La probabilidad de que el primer equipo gane el play-off es: " << probabilidad << endl;

    return 0;
}
