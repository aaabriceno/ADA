#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void minimizar_suma_bt(const vector<int>& alturas_alumnos, const vector<int>& longitud_esquis, vector<bool>& visitado, int idx, int current_sum, int& min_difference) {
    int n = alturas_alumnos.size();
    if (idx == n) { // Si todos los alumnos tienen esquís
        min_difference = min(min_difference, current_sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visitado[i]) { // Si el esquí no ha sido asignado
            visitado[i] = true;
            int diff = abs(alturas_alumnos[idx] - longitud_esquis[i]);
            if (current_sum + diff < min_difference) { // Podar si no es prometedor
                minimizar_suma_bt(alturas_alumnos, longitud_esquis, visitado, idx + 1, current_sum + diff, min_difference);
            }
            visitado[i] = false; // minimizar_suma_bt
        }
    }
}

int main() {
    // Entrada
    vector<int> alturas_alumnos = { 178, 168, 190, 170 };
    vector<int> longitud_esquis = { 183, 188, 168, 175 };
    int n = alturas_alumnos.size();

    // Ordenar las listas para minimizar diferencias
    sort(alturas_alumnos.begin(), alturas_alumnos.end());
    sort(longitud_esquis.begin(), longitud_esquis.end());

    // Vector para rastrear esquís asignados
    vector<bool> visitado(n, false);
    int min_difference = INT_MAX; // Diferencia mínima encontrada

    // Llamada inicial al backtracking
    minimizar_suma_bt(alturas_alumnos, longitud_esquis, visitado, 0, 0, min_difference);

    // Salida
    cout << "Mínima suma de diferencias: " << min_difference << endl;
    return 0;
}
