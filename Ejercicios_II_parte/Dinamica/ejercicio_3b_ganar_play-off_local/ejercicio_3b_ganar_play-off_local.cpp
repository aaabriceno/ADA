#include <iostream>
#include <vector>
using namespace std;

// Función para calcular la probabilidad P(i, j)
double calcularProbabilidad(int i, int j, double PL, double PV) {
    // Crear una matriz dp de tamaño (i+1) x (j+1)
    vector<vector<double>> dp(i + 1, vector<double>(j + 1, 0));

    // Caso base: Si el primer equipo necesita ganar 0 partidos, el segundo equipo debe ganar todos
    for (int k = 0; k <= j; ++k) {
        dp[0][k] = 1.0;
    }

    // Caso base: Si el segundo equipo necesita ganar 0 partidos, el primer equipo gana
    for (int k = 0; k <= i; ++k) {
        dp[k][0] = 0.0;
    }

    // Calcular la probabilidad para cada par (i, j)
    for (int x = 1; x <= i; ++x) {
        for (int y = 1; y <= j; ++y) {
            // Determinamos si el primer equipo juega de local o visitante
            double probabilidadPartido = (x + y) % 2 == 0 ? PL : PV; // Partido en casa si (x + y) es par, fuera si es impar
            dp[x][y] = probabilidadPartido * dp[x - 1][y] + (1 - probabilidadPartido) * dp[x][y - 1];
        }
    }

    // Retornar la probabilidad de que el primer equipo gane el play-off
    return dp[i][j];
}

int main() {
    int n;
    double PL, PV;

    cout << "Numero de victorias necesarias para ganar el play-off (n): ";
    cin >> n;

    do {
        cout << "Probabilidad de que Informáticos CB gane un partido como local (PL): ";
        cin >> PL;

        PV = 1.0 - PL;

        if (PL <= PV) {
            cout << "Error: La probabilidad de ganar como local (PL) debe ser mayor que la probabilidad de ganar como visitante (PV)." << endl;
        }
    } while (PL <= PV);

    cout << "La probabilidad de ganar como visitante (PL) será: " << PL << endl;
    cout << "La probabilidad de ganar como visitante (PV) será: " << PV << endl;

    // Calcular y mostrar la probabilidad de que el primer equipo gane el play-off
    double probabilidad = calcularProbabilidad(n, n, PL, PV);
    cout << "La probabilidad de que Informaticos CB gane el play-off es: " << probabilidad << endl;

    return 0;
}
