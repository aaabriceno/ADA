/*
Programar el problema de la mochila para el siguiente conjunto de datos, estan en la diapositvas

n= 3, M= 6, p= (2, 3, 4), b= (1, 2, 5)

Mostrar la tabla y la solucion con un vector de 1 si es parte de la solucion y 0 si no lo es
*/

#include <iostream>
#include <vector>
using namespace std;

struct Objeto {
    int peso;
    int beneficio;
};

void mochila01(const vector<Objeto>& objetos, int capacidad) {
    int n = objetos.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (objetos[i - 1].peso <= w) {
                dp[i][w] = max(dp[i - 1][w], objetos[i - 1].beneficio + dp[i - 1][w - objetos[i - 1].peso]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
 
    cout << "Tabla de beneficios (dp):\n"; // Mostrar la tabla dp
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacidad; ++w) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    
    int res = dp[n][capacidad]; // Construir la solución en forma de vector binario
    int w = capacidad;
    vector<int> solucion(n, 0);

    for (int i = n; i > 0 && res > 0; --i) {
        if (res != dp[i - 1][w]) {
            solucion[i - 1] = 1;  // Marcar el objeto como parte de la solución
            res -= objetos[i - 1].beneficio;
            w -= objetos[i - 1].peso;
        }
    }

    cout << "Vector de solucion (1 si es parte de la solucion, 0 si no lo es): ";
    for (int i = 0; i < solucion.size(); ++i) {
        cout << solucion[i] << " ";
    }
    cout << endl;
    cout << "Beneficio total: " << dp[n][capacidad] << endl;
}

int main() {
    vector<Objeto> objetos = { {2, 1}, {3, 2}, {4, 5} };
    int capacidad = 6;

    cout << "Mochila de capacidad W=6:\n";
    mochila01(objetos, capacidad);

    return 0;
}
