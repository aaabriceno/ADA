#include <iostream>
#include <vector>

using namespace std;

// Movimientos posibles: {abajo, arriba, derecha, izquierda}
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool isValid(int x, int y, int n, vector<vector<bool>>& M, vector<vector<bool>>& visited) {
    return (x >= 0 && x < n && y >= 0 && y < n && M[x][y] && !visited[x][y]);
}

bool solveMaze(int x, int y, int endX, int endY, int n, vector<vector<bool>>& M, vector<vector<bool>>& visited, vector<pair<int, int>>& path) {
    // Si hemos alcanzado la casilla de salida
    if (x == endX && y == endY) {
        path.push_back({ x, y });
        return true;
    }

    // Marcar la celda actual como visitada
    visited[x][y] = true;
    path.push_back({ x, y });

    // Intentar moverse en las 4 direcciones posibles
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, n, M, visited)) {
            if (solveMaze(newX, newY, endX, endY, n, M, visited, path)) {
                return true;
            }
        }
    }

    // Backtracking: desmarcar la celda actual y removerla del camino
    visited[x][y] = false;
    path.pop_back();
    return false;
}

int main() {
    int n = 5; // Tamaño del laberinto
    vector<vector<bool>> M = {
        {true, true, false, false, false},
        {false, true, true, true, false},
        {false, true, false, true, false},
        {false, true, false, true, true},
        {false, false, false, true, true}
    };

    int startX = 0, startY = 0; // Posición inicial (I)
    int endX = 4, endY = 4;     // Posición final (S)

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<int, int>> path;

    if (solveMaze(startX, startY, endX, endY, n, M, visited, path)) {
        cout << "Camino encontrado: \n";
        for (auto cell : path) {
            cout << "(" << cell.first << ", " << cell.second << ") ";
        }
        cout << endl;
    }
    else {
        cout << "No hay camino válido.\n";
    }

    return 0;
}
