#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcularBeneficio(const vector<int>& asignacion, const vector<vector<int>>& B, int n) {
    int beneficio = 0;
    for (int i = 0; i < n; ++i) {
        beneficio += B[i][asignacion[i]];
    }
    return beneficio;
}

// Backtracking para encontrar la mejor asignación
void resolverAsignacion(vector<int>& asignacion, vector<bool>& usado, int nivel, int n, const vector<vector<int>>& B, int& mejor_beneficio, vector<int>& mejor_asignacion) {
    if (nivel == n) { // Si se asignaron todas las tareas
        int beneficio = calcularBeneficio(asignacion, B, n);
        if (beneficio > mejor_beneficio) {
            mejor_beneficio = beneficio;
            mejor_asignacion = asignacion;
        }
        return;
    }

    for (int tarea = 0; tarea < n; ++tarea) {
        if (!usado[tarea]) { // Si la tarea no ha sido asignada
            asignacion[nivel] = tarea;
            usado[tarea] = true;
            resolverAsignacion(asignacion, usado, nivel + 1, n, B, mejor_beneficio, mejor_asignacion);
            usado[tarea] = false; // Backtracking
        }
    }
}

int main() {
    int n = 3;
    vector<vector<int>> B = {
        {4, 9, 1},
        {7, 2, 3},
        {6, 3, 5}
    };

    int mejor_beneficio = 0;
    vector<int> mejor_asignacion;

    cout << "Matriz de beneficios:\n";
    for (const auto& fila : B) {
        for (int val : fila) {
            cout << val << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    vector<int> asignacion(n, -1);
    vector<bool> usado(n, false);

    resolverAsignacion(asignacion, usado, 0, n, B, mejor_beneficio, mejor_asignacion);

    cout << "Mejor beneficio: " << mejor_beneficio << "\n";
    cout << "Matriz de asignaciones:\n";

    vector<vector<int>> matriz_sol(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        matriz_sol[i][mejor_asignacion[i]] = 1;
    }

    // Imprimir la matriz de asignaciones
    for (const auto& fila : matriz_sol) {
        for (int val : fila) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
