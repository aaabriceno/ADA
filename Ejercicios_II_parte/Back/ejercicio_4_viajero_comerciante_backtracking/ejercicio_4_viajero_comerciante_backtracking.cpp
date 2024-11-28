#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Matriz de distancias
const int N = 5; // Número de ciudades
int dist[N][N] = {
    {0, 3, 10, 11, 7},
    {3, 0, 8, 12, 9},
    {10, 8, 0, 9, 4},
    {11, 12, 9, 0, 5},
    {7, 9, 4, 5, 0}
};

bool visited[N]; // Ciudades visitadas
int min_cost = INT_MAX; // Costo mínimo
vector<int> best_path; // Mejor ruta

void tsp(int city, int count, int cost, vector<int>& path) {
    if (count == N && dist[city][0] > 0) { // Ruta completa
        cost += dist[city][0]; // Regresa a la ciudad inicial
        if (cost < min_cost) { // Actualiza la mejor solución
            min_cost = cost;
            best_path = path;
            best_path.push_back(0); // Añade la ciudad inicial al final
        }
        return;
    }

    // Explora las ciudades no visitadas
    for (int next_city = 0; next_city < N; ++next_city) {
        if (!visited[next_city] && dist[city][next_city] > 0) {
            visited[next_city] = true;
            path.push_back(next_city);
            tsp(next_city, count + 1, cost + dist[city][next_city], path);
            path.pop_back();
            visited[next_city] = false;
        }
    }
}

int main() {
    vector<int> path; // Ruta actual
    path.push_back(0); // Inicia desde la ciudad A (0)
    fill(visited, visited + N, false);
    visited[0] = true;

    tsp(0, 1, 0, path);

    // Imprime el resultado
    cout << "Costo minimo: " << min_cost << endl;
    cout << "Mejor ruta: ";
    for (int city : best_path) {
        cout << char('A' + city) << " ";
    }
    cout << endl;

    return 0;
}
