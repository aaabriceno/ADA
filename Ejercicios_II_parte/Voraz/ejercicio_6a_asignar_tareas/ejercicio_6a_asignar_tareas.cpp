/*
Supongamos que disponemos de n trabajadores y n tareas. Sea cij > 0 el coste de
asignarle el trabajo j al trabajador i. Una asignación válida es aquélla en la que a
cada trabajador le corresponde una tarea y cada tarea la realiza un trabajador
diferente. Dada una asignación válida, definimos el coste de dicha asignación
como la suma total de los costes individuales.
a. Diseñe distintas estrategias greedy para asignar tareas.
b. Encuentre contrajemplos que demuestren que ninguna de ellas nos
permite encontrar la solución óptima con un algoritmo greedy.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Asignacion {
    int trabajador;
    int tarea;
    int costo;

    Asignacion(int t, int j, int c) : trabajador(t), tarea(j), costo(c) {}
};

// Función para imprimir una asignación
void imprimirAsignacion(const Asignacion& asignacion) {
    std::cout << "Trabajador " << asignacion.trabajador << " -> Tarea " << asignacion.tarea << " (Costo: " << asignacion.costo << ")\n";
}

// Estrategia Greedy: Asignación por Menor Costo Individual
std::vector<Asignacion> asignacionMenorCostoIndividual(const std::vector<std::vector<int>>& costes) {
    int n = costes.size();
    std::vector<Asignacion> asignaciones;

    for (int j = 0; j < n; ++j) {
        int mejorTrabajador = 0;
        for (int i = 1; i < n; ++i) {
            if (costes[i][j] < costes[mejorTrabajador][j]) {
                mejorTrabajador = i;
            }
        }
        asignaciones.emplace_back(mejorTrabajador, j, costes[mejorTrabajador][j]);
    }

    return asignaciones;
}

// Estrategia Greedy: Asignación por Menor Costo Total
std::vector<Asignacion> asignacionMenorCostoTotal(const std::vector<std::vector<int>>& costes) {
    int n = costes.size();
    std::vector<Asignacion> asignaciones;
    std::vector<int> costosTotales(n, 0);

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            costosTotales[i] += costes[i][j];
        }
    }

    for (int j = 0; j < n; ++j) {
        int mejorTrabajador = 0;
        for (int i = 1; i < n; ++i) {
            if (costosTotales[i] < costosTotales[mejorTrabajador]) {
                mejorTrabajador = i;
            }
        }
        asignaciones.emplace_back(mejorTrabajador, j, costes[mejorTrabajador][j]);
        costosTotales[mejorTrabajador] = std::numeric_limits<int>::max();
    }

    return asignaciones;
}

// Estrategia Greedy: Asignación por Mejor Relación Costo-Beneficio
std::vector<Asignacion> asignacionMejorRelacionCostoBeneficio(const std::vector<std::vector<int>>& costes) {
    int n = costes.size();
    std::vector<Asignacion> asignaciones;
    std::vector<double> relacionesCostoBeneficio(n, 0.0);
    std::vector<int> costosTotales(n, 0);

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            relacionesCostoBeneficio[i] = static_cast<double>(costes[i][j]) / (1.0 + costosTotales[i]);
        }
        int mejorTrabajador = std::max_element(relacionesCostoBeneficio.begin(), relacionesCostoBeneficio.end()) - relacionesCostoBeneficio.begin();
        asignaciones.emplace_back(mejorTrabajador, j, costes[mejorTrabajador][j]);
        costosTotales[mejorTrabajador] += costes[mejorTrabajador][j];
    }

    return asignaciones;
}

// Función para imprimir asignaciones y el costo total
void imprimirAsignaciones(const std::vector<Asignacion>& asignaciones) {
    int costoTotal = 0;
    for (const auto& asignacion : asignaciones) {
        imprimirAsignacion(asignacion);
        costoTotal += asignacion.costo;
    }
    std::cout << "Costo Total: " << costoTotal << "\n";
}

int main() {
    // Ejemplo de uso
    std::vector<std::vector<int>> costes1 = { {2, 5, 7}, {1, 3, 6}, {4, 8, 9} };
    std::vector<std::vector<int>> costes2 = { {2, 1, 3}, {1, 3, 2}, {4, 2, 5} };

    std::cout << "Asignacion por Menor Costo Individual:\n";
    std::vector<Asignacion> asignaciones1 = asignacionMenorCostoIndividual(costes1);
    imprimirAsignaciones(asignaciones1);

    std::cout << "\nAsignacion por Menor Costo Total:\n";
    std::vector<Asignacion> asignaciones2 = asignacionMenorCostoTotal(costes2);
    imprimirAsignaciones(asignaciones2);

    std::cout << "\nAsignacion por Mejor Relacion Costo-Beneficio:\n";
    std::vector<Asignacion> asignaciones3 = asignacionMejorRelacionCostoBeneficio(costes2);
    imprimirAsignaciones(asignaciones3);

    return 0;
}