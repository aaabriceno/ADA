#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> cambioMinimoMonedas(const vector<int>& monedas, int cantidad) {
    int n = monedas.size();
    vector<vector<int>> D(n + 1, vector<int>(cantidad + 1, INT_MAX));
    vector<vector<int>> seleccion(n + 1, vector<int>(cantidad + 1, 0));

    for (int i = 0; i <= n; ++i)
        D[i][0] = 0;

    // Llenar la matriz D y seleccion
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= cantidad; ++j) {
            if (monedas[i - 1] <= j) {
                if (D[i][j - monedas[i - 1]] != INT_MAX &&
                    1 + D[i][j - monedas[i - 1]] < D[i - 1][j]) {
                    D[i][j] = 1 + D[i][j - monedas[i - 1]];
                    seleccion[i][j] = 1;
                }
                else {
                    D[i][j] = D[i - 1][j];
                }
            }
            else {
                D[i][j] = D[i - 1][j];
            }
        }
    }

    cout << "\nTabla D (Minimo numero de monedas):\n";
    for (int i = 1; i <= n; ++i) {
        cout << "i = " << i << ": ";
        for (int j = 0; j <= cantidad; ++j) {
            if (D[i][j] == INT_MAX)
                cout << "∞ ";
            else
                cout << D[i][j] << " ";
        }
        cout << "\n";
    }

    vector<int> resultado(n, 0);
    int i = n, j = cantidad;

    while (i > 0 && j > 0) {
        if (seleccion[i][j] == 1) {
            resultado[i - 1]++;
            j -= monedas[i - 1];
        }
        else {
            --i;
        }
    }

    if (D[n][cantidad] == INT_MAX)
        return {};

    return resultado;
}

int main() {
    vector<int> monedas = { 1, 4, 6 }; //monedas
    int cantidad = 8;  // Cantidad

    if (cantidad < 0) {
        cout << "El monto es negativo, no se puede calcular el mínimo de monedas.\n";
        return 0;
    }

    vector<int> resultado = cambioMinimoMonedas(monedas, cantidad);

    if (resultado.empty()) {
        cout << "No es posible formar la cantidad con las monedas dadas.\n";
    }

    else {
        cout << "\nMonedas necesarias:\n";
        for (size_t i = 0; i < monedas.size(); ++i) {
            cout << "Moneda " << monedas[i] << ": " << resultado[i] << "\n";
        }
    }

    return 0;
}