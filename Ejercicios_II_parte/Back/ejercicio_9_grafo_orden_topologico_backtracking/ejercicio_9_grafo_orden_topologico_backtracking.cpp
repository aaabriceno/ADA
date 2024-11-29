#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Función auxiliar para realizar DFS y encontrar el orden topológico
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& order) {
    visited[node] = true; // Marcar el nodo como visitado

    // Explorar todos los vecinos
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, order);
        }
    }

    // Al finalizar la exploración del nodo, añadirlo a la pila
    order.push(node);
}

// Función principal para encontrar la ordenación topológica
vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false); // Marcar todos los nodos como no visitados
    stack<int> order;              // Pila para almacenar el orden topológico

    // Llamar a DFS para cada nodo no visitado
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, order);
        }
    }

    // Convertir la pila en una lista de ordenación topológica
    vector<int> result;
    while (!order.empty()) {
        result.push_back(order.top());
        order.pop();
    }

    return result;
}

int main() {
    int n = 6; // Número de nodos
    vector<vector<int>> adj = {
        {1, 2}, // Vecinos del nodo 0
        {3},    // Vecinos del nodo 1
        {3},    // Vecinos del nodo 2
        {4, 5}, // Vecinos del nodo 3
        {},     // Vecinos del nodo 4
        {}      // Vecinos del nodo 5
    };

    vector<int> order = topologicalSort(n, adj);

    cout << "Ordenacion topologica: ";
    for (int node : order) {
        cout << node << " ";
    }

    return 0;
}
