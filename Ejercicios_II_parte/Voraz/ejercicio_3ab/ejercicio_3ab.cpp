/*
Tenemos que completar un conjunto de n tareas con plazos límite. Cada una de
las tareas consume la misma cantidad de tiempo (una unidad) y, en un instante
determinado, podemos realizar únicamente una tarea. La tarea i tiene como
plazo límite di
 y produce un beneficio gi
 (gi
 > 0) sólo si la tarea se realiza en un
instante de tiempo t ≤ di
.
a. Diseñe un algoritmo greedy que nos permita seleccionar el conjunto de
tareas que nos asegure el mayor beneficio posible.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Tarea {
    int id;
    int beneficio;
    int plazoLimite;

    Tarea(int i, int g, int d) : id(i), beneficio(g), plazoLimite(d) {}
};

bool compararPorBeneficio(const Tarea& a, const Tarea& b) {
    return a.beneficio > b.beneficio; // Ordenar de forma no decreciente por beneficio
}

void maximizarBeneficio(std::vector<Tarea>& tareas) {
    std::sort(tareas.begin(), tareas.end(), compararPorBeneficio);

    int n = tareas.size();
    std::vector<bool> tiempoOcupado(n, false); // Vector para registrar tiempos ocupados
    int beneficioTotal = 0;

    for (const Tarea& tarea : tareas) {
        for (int t = std::min(n, tarea.plazoLimite) - 1; t >= 0; t--) { // Verificar tiempos disponibles dentro del plazo límite
            if (!tiempoOcupado[t]) {
                tiempoOcupado[t] = true;
                beneficioTotal += tarea.beneficio;
                std::cout << "Realizada tarea " << tarea.id << " con beneficio " << tarea.beneficio << std::endl;
                break;
            }
        }
    }

    std::cout << "Beneficio total: " << beneficioTotal << std::endl;
}


int main() {
    // Ejemplo de uso
    std::vector<Tarea> tareas = { {1, 35, 2}, {2, 10, 1}, {3, 15, 2}, {4, 30, 1} ,{5, 80, 1} ,{6, 120, 1} ,{7, 50, 2} };

    maximizarBeneficio(tareas);

    return 0;
}
