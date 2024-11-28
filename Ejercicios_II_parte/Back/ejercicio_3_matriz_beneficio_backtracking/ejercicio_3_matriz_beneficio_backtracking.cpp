/* Ejercicio 3 (Todos lo hacen) - Backtracking*/

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

void resolverAsignacion(vector<int>& asignacion, vector<bool>& usado, int nivel, int n, const vector<vector<int>>& B, int& mejor_beneficio, vector<int>& mejor_asignacion) {
    if (nivel == n) { // Si se asignaron todas las tareas
        int beneficio = calcularBeneficio(asignacion, B, n);
        if (beneficio > mejor_beneficio) {
            mejor_beneficio = beneficio;
            mejor_asignacion = asignacion;
        }
        return;
    } 
	// Si no se han asignado todas las tareas
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
    int n = 4;
    vector<vector<int>> B = {
        {94,1,54,58},
        {74,10,88,82},
        {62,88,8,76 },
        {11,74,81,21}

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
    for (const auto& fila : matriz_sol) {
        for (int val : fila) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}