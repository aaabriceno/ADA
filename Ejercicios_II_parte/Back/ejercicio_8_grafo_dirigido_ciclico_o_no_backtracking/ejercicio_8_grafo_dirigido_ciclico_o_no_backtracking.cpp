#include <iostream>
#include <vector>
using namespace std;

// Función para detectar ciclos en un grafo dirigido usando backtracking
bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inPath) {
    visited[node] = true;   // Marcar el nodo como visitado
    inPath[node] = true;    // Añadir el nodo al camino actual

    // Explorar los vecinos del nodo actual
    for (int neighbor : adj[node]) {
        // Si el vecino ya está en el camino actual, encontramos un ciclo
        if (inPath[neighbor]) {
            return true;
        }
        // Si el vecino no fue visitado, continuar el DFS
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, inPath)) {
                return true; // Si un ciclo es encontrado en la recursión, detener
            }
        }
    }

    inPath[node] = false; // Quitar el nodo del camino actual al retroceder
    return false;         // No se encontró ciclo en este camino
}

// Función principal para determinar si el grafo tiene ciclos
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false); // Arreglo para marcar nodos visitados
    vector<bool> inPath(n, false);  // Arreglo para rastrear nodos en el camino actual

    // Llamar a DFS desde cada nodo no visitado
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, inPath)) {
                return true; // Si se encuentra un ciclo, retornar true
            }
        }
    }
    return false; // No se encontró ningún ciclo
}

int main() {
    int n = 5; // Número de nodos
    vector<vector<int>> adj = {
        {1},    // Vecinos del nodo 0
        {2},    // Vecinos del nodo 1
        {3},    // Vecinos del nodo 2
        {4},    // Vecinos del nodo 3
        {}      // Vecinos del nodo 4
    };

    if (hasCycle(n, adj)) {
        cout << "El grafo tiene ciclos.\n";
    }
    else {
        cout << "El grafo es un DAG (grafo dirigido aciclico).\n";
    }

    return 0;
}
