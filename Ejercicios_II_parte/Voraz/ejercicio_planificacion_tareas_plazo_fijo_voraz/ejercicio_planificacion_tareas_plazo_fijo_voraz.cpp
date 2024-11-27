#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tarea {
    int ganancias;
    int tiempo;
    int num_tarea;
};

bool compararganancias(const tarea& a, const tarea& b) {
    return a.ganancias > b.ganancias;
}

bool esFactible(const std::vector<int>& planificacion, int tiempo, int posicion) {
    return (posicion < tiempo) && (planificacion[posicion] == -1);
}

int planificartareas(int n, const std::vector<int>& gananciass, const std::vector<int>& tiempos) {
    std::vector<tarea> tareas(n);
    for (int i = 0; i < n; ++i) {
        tareas[i] = { gananciass[i], tiempos[i], i + 1 }; // i + 1 para índice 1-based
    }

    sort(tareas.begin(), tareas.end(), compararganancias);

    vector<int> planificacion(n, -1);
    int gananciasTotal = 0;

    for (const auto& tarea : tareas) {
        // Intentar colocar la tarea en la última posición posible dentro de su tiempo
        for (int j = tarea.tiempo - 1; j >= 0; --j) {
            if (esFactible(planificacion, tarea.tiempo, j)) { //factibilidad de la tarea
                planificacion[j] = tarea.num_tarea;
                gananciasTotal += tarea.ganancias;
                break;
            }
        }
    }

    // Mostrar la planificación de tareas
    cout << "tareas planificadas (dia: tarea): ";
    for (int i = 0; i < n; ++i) {
        if (planificacion[i] != -1) {
            cout << "(" << i + 1 << ": " << planificacion[i] << ") ";
        }
    }
    cout << "\nganancias total: " << gananciasTotal << endl;

    return gananciasTotal;
}

int main() {
    int n = 10;
    vector<int> gananciass = { 10, 20, 8, 15, 30, 10, 5, 10, 2, 9 };
    vector<int> tiempos = { 1, 4, 4, 1, 4, 2, 3, 4, 5, 4 };

    int gananciasTotal = planificartareas(n, gananciass, tiempos);

    return 0;
}