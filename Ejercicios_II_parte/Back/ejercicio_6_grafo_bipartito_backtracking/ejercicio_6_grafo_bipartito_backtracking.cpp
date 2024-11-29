#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Función para verificar si el grafo es bipartito
bool isBipartite(int n, vector<vector<int>>& adj) {
    vector<int> color(n, 0); // 0: no visitado, 1: color 1, -1: color 2

    // Iterar por todos los nodos (en caso de que el grafo no sea conexo)
    for (int start = 0; start < n; start++) {
        if (color[start] != 0) continue; // Nodo ya visitado

        // Iniciar BFS
        queue<int> q;
        q.push(start);
        color[start] = 1; // Asignar el primer color

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Iterar sobre los vecinos
            for (int v : adj[u]) {
                if (color[v] == 0) {
                    // Asignar el color opuesto al vecino
                    color[v] = -color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    // Si el vecino tiene el mismo color, no es bipartito
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n = 5; // Número de nodos
    vector<vector<int>> adj = {
        {1, 3},     // Vecinos del nodo 0
        {0, 2},     // Vecinos del nodo 1
        {1, 3},     // Vecinos del nodo 2
        {0, 2, 4},  // Vecinos del nodo 3
        {3}         // Vecinos del nodo 4
    };

    if (isBipartite(n, adj)) {
        cout << "El grafo es bipartito.\n";
    }
    else {
        cout << "El grafo no es bipartito.\n";
    }

    return 0;
}
