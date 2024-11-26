#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <bitset>
using namespace std;

const int INF = numeric_limits<int>::max();

int g(int i, int S, const vector<vector<int>>& grafo, vector<vector<int>>& memo) {
    int n = grafo.size();

    if (S == 0) {
        // Todos los nodos han sido visitados
        return grafo[i][0];
    }

    if (memo[i][S] != -1) {
        // Ya se ha calculado este caso
        return memo[i][S];
    }

    int minDist = INF;
    for (int k = 0; k < n; ++k) {
        if (S & (1 << k)) {
            // Si el k-ésimo bit está encendido (k está en S)
            minDist = min(minDist, grafo[i][k] + g(k, S - (1 << k), grafo, memo));
        }
    }

    return memo[i][S] = minDist;
}

int reconstruirCamino(int i, int S, const vector<vector<int>>& grafo, vector<vector<int>>& memo, vector<int>& path) {
    int n = grafo.size();

    if (S == 0) {
        path.push_back(0); // Volver al nodo inicial
        return grafo[i][0];
    }

    for (int k = 0; k < n; ++k) {
        if (S & (1 << k)) {
            int remaining = S - (1 << k);
            if (memo[i][S] == grafo[i][k] + g(k, remaining, grafo, memo)) {
                path.push_back(k);
                return reconstruirCamino(k, remaining, grafo, memo, path);
            }
        }
    }
    return INF; // Caso no debería ocurrir
}

int tsp(const vector<vector<int>>& grafo) {
    int n = grafo.size();

    // Inicializar la tabla de memorización
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));

    // Inicializar el conjunto S (todos los nodos menos el nodo 1)
    int S = (1 << n) - 2;

    // Calcular la longitud del circuito hamiltoniano minimal
    int resultado = g(0, S, grafo, memo);

    // Reconstruir el camino
    vector<int> path = { 0 };
    reconstruirCamino(0, S, grafo, memo, path);

    // Imprimir el camino
    cout << "Camino optimo: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] + 1; // Convertir a base 1
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;

    return resultado;
}

int main() {
    vector<vector<int>> grafo = {
        {0, 29, 20, 21},
        {29, 0, 15, 18},
        {20, 15, 0, 26},
        {21, 18, 26, 0},

    };

    // Validar que el grafo sea cuadrado
    int n = grafo.size();
    for (const auto& row : grafo) {
        if (row.size() != n) {
            cerr << "El grafo no es cuadrado, abortando." << endl;
            return -1;
        }
    }

    int resultado = tsp(grafo);

    cout << "Longitud del circuito hamiltoniano minimal: " << resultado << endl;

    return 0;
}
