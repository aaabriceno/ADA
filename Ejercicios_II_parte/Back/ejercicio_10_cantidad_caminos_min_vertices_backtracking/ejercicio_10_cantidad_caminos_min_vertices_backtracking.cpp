#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Función BFS para contar el número de caminos de longitud mínima
int bfs_count_paths(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();  // Número de nodos
    vector<int> dist(n, -1);  // Inicializar distancias con -1 (no visitado)
    vector<int> count(n, 0);  // Inicializar el número de caminos con 0
    queue<int> q;

    // Inicializar el nodo de inicio
    dist[start] = 0;
    count[start] = 1;
    q.push(start);

    // Realizar BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            // Si el nodo v no ha sido visitado, asignamos distancia y caminos
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                count[v] = count[u];
                q.push(v);
            }
            // Si ya se visitó y es un camino de longitud mínima
            else if (dist[v] == dist[u] + 1) {
                count[v] += count[u];
            }
        }
    }

    return count[end];  // El número de caminos de longitud mínima desde start a end
}

int main() {
    // Ejemplo de grafo
    vector<vector<int>> graph = {
        {1, 2},    // Nodo 0 conecta con 1 y 2
        {0, 2, 3}, // Nodo 1 conecta con 0, 2 y 3
        {0, 1, 3}, // Nodo 2 conecta con 0, 1 y 3
        {1, 2, 4}, // Nodo 3 conecta con 1, 2 y 4
        {3}        // Nodo 4 conecta con 3
    };

    int start = 0;  // Nodo de inicio
    int end = 4;    // Nodo de destino

    // Llamada a la función BFS para contar los caminos de longitud mínima
    int num_paths = bfs_count_paths(graph, start, end);

    cout << "Numero de caminos de longitud minima de " << start << " a " << end << ": " << num_paths << endl;

    return 0;
}
