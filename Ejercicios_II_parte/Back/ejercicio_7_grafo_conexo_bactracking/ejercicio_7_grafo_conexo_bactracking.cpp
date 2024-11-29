#include <iostream>
#include <vector>
using namespace std;

// Función de backtracking para recorrer el grafo
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; // Marcar el nodo como visitado

    // Explorar los vecinos no visitados
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Función principal para comprobar si el grafo es conexo
bool isConnected(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false); // Arreglo para marcar nodos visitados

    // Llamar al backtracking desde el nodo 0
    dfs(0, adj, visited);

    // Verificar si todos los nodos fueron visitados
    for (bool v : visited) {
        if (!v) return false; // Si algún nodo no fue visitado, no es conexo
    }

    return true;
}

int main() {
    int n = 5; // Número de nodos
    vector<vector<int>> adj = {
        {1, 2},   // Vecinos del nodo 0
        {0, 3},   // Vecinos del nodo 1
        {0, 3},   // Vecinos del nodo 2
        {1, 2, 4},// Vecinos del nodo 3
        {3}       // Vecinos del nodo 4
    };

    if (isConnected(n, adj)) {
        cout << "El grafo es conexo.\n";
    }
    else {
        cout << "El grafo no es conexo.\n";
    }

    return 0;
}
