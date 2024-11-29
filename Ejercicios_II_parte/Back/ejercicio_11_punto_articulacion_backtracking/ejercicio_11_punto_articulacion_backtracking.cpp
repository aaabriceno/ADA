#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V; // Número de vértices
    vector<vector<int>> adj; // Lista de adyacencia

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Función para agregar una arista no dirigida
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS para encontrar puntos de articulación
    void dfs(int u, vector<int>& num, vector<int>& low, vector<int>& parent, vector<bool>& visited, vector<bool>& articulationPoint, int& time) {
        visited[u] = true;
        num[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                children++;
                dfs(v, num, low, parent, visited, articulationPoint, time);

                // Check if the subtree rooted at v has a connection back to one of the ancestors of u
                low[u] = min(low[u], low[v]);

                // u is an articulation point in the following cases:
                // 1. u is the root and has more than one child.
                // 2. u is not the root and low[v] >= num[u]
                if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= num[u])) {
                    articulationPoint[u] = true;
                }
            }
            else if (v != parent[u]) { // Back edge
                low[u] = min(low[u], num[v]);
            }
        }
    }

    // Función principal para encontrar los puntos de articulación
    void findArticulationPoints() {
        vector<int> num(V, -1);  // Números de descubrimiento
        vector<int> low(V, -1);  // Valores low
        vector<int> parent(V, -1);  // Padres en el DFS
        vector<bool> visited(V, false);  // Marcadores de visitados
        vector<bool> articulationPoint(V, false);  // Puntos de articulación

        int time = 0;

        // Realizar DFS para todos los vértices no visitados
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, num, low, parent, visited, articulationPoint, time);
            }
        }

        // Imprimir los puntos de articulación
        cout << "Puntos de articulacion: ";
        for (int i = 0; i < V; i++) {
            if (articulationPoint[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5); // Crear un grafo con 5 vértices

    // Agregar aristas
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.findArticulationPoints(); // Encontrar y mostrar los puntos de articulación

    return 0;
}
