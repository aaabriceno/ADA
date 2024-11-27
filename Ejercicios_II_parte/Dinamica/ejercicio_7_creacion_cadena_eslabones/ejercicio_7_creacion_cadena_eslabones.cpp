#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Función que calcula el costo mínimo de unir los eslabones
int calcularCostoMinimo(const vector<int>& pesos) {
    int n = pesos.size();

    // dp[i][j] guarda el costo mínimo para unir los eslabones entre i y j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // suma[i][j] guarda la suma total de los pesos entre i y j
    vector<vector<int>> suma(n, vector<int>(n, 0));

    // Llenar la matriz de sumas
    for (int i = 0; i < n; ++i) {
        suma[i][i] = pesos[i];
        for (int j = i + 1; j < n; ++j) {
            suma[i][j] = suma[i][j - 1] + pesos[j];
        }
    }

    // Ahora, calculamos el costo mínimo para unir las subcadenas
    // Solo se calculan los costos de los intervalos mayores o iguales a 2
    for (int len = 2; len <= n; ++len) {  // longitud de subcadena
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;  // Inicializar al valor máximo

            // Probar todas las posibles divisiones de la subcadena
            for (int k = i; k < j; ++k) {
                int costo = dp[i][k] + dp[k + 1][j] + suma[i][k] + suma[k + 1][j];
                dp[i][j] = min(dp[i][j], costo);
            }
        }
    }

    // El costo mínimo total es el valor en dp[0][n-1], que es el costo de unir todos los eslabones
    return dp[0][n - 1];
}

int main() {
    // Definir los pesos de los eslabones
    vector<int> pesos = {3,2,1 };  // Pesos de los eslabones

    // Calcular el costo mínimo total
    int costoMinimo = calcularCostoMinimo(pesos);

    cout << "Costo total de las uniones: " << costoMinimo << endl;

    return 0;
}
