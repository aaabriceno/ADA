#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Variables globales
int n = 3; // Número de personas/tareas
vector<vector<int>> B = {
    {4, 9, 1},
    {7, 2, 3},
    {6, 3, 5}
}; // Matriz de beneficios
int voa = 0; // Mejor beneficio encontrado
vector<int> mejor_asignacion; // Mejor asignación encontrada

// Función para calcular el beneficio total de una asignación
int calcularBeneficio(const vector<int>& asignacion) {
    int beneficio = 0;
    for (int i = 0; i < n; ++i) {
        beneficio += B[i][asignacion[i]];
    }
    return beneficio;
}

// Backtracking para encontrar la mejor asignación
void resolverAsignacion(vector<int>& asignacion, vector<bool>& usado, int nivel) {
    if (nivel == n) { // Si se asignaron todas las tareas
        int beneficio = calcularBeneficio(asignacion);
        if (beneficio > voa) {
            voa = beneficio;
            mejor_asignacion = asignacion;
        }
        return;
    }

    for (int tarea = 0; tarea < n; ++tarea) {
        if (!usado[tarea]) { // Si la tarea no ha sido asignada
            asignacion[nivel] = tarea;
            usado[tarea] = true;
            resolverAsignacion(asignacion, usado, nivel + 1);
            usado[tarea] = false; // Backtracking
        }
    }
}

int main() {
    // Imprimir la matriz de beneficios
    cout << "Matriz de beneficios:\n";
    for (const auto& fila : B) {
        for (int val : fila) {
            cout << val << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    // Inicialización
    vector<int> asignacion(n, -1); // Vector para almacenar la asignación actual
    vector<bool> usado(n, false); // Vector para marcar tareas asignadas

    // Resolver el problema de asignación
    resolverAsignacion(asignacion, usado, 0);

    // Mostrar el resultado
    cout << "Mejor beneficio: " << voa << "\n";
    cout << "Matriz de asignaciones:\n";

    // Construir la matriz de asignaciones a partir de la mejor asignación
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
