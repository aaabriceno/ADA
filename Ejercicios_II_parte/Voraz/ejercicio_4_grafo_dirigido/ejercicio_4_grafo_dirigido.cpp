/*
Consideremos un grafo no dirigido G = (V, E). Un conjunto de nodos U se dice
que es un recubrimiento de G si U es un subconjunto de V tal que cada arista en
E incide en, al menos, un vértice de U. Un conjunto de nodos es un
recubrimiento minimal de G si es un recubrimiento con el número mínimo
posible de nodos.
a. Diseñe un algoritmo greedy para obtener un recubrimiento de G.
b. Indique si el algoritmo greedy devuelve un recubrimiento minimal para
cualquier grafo si, como función de selección, se escoge el nodo con
mayor grado de incidencia de entre los nodos aún no seleccionados.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

struct Arista {
    int nodo1;
    int nodo2;

    Arista(int u, int v) : nodo1(u), nodo2(v) {}
};

std::unordered_set<int> recubrimientoGreedy(std::vector<Arista>& aristas) {
    std::unordered_set<int> recubrimiento;
    std::unordered_map<int, int> grado;

    // Calcular el grado de cada nodo
    for (const Arista& arista : aristas) {
        grado[arista.nodo1]++;
        grado[arista.nodo2]++;
    }

    while (!aristas.empty()) {
        // Encontrar el nodo con el mayor grado de incidencia
        auto max_it = std::max_element(grado.begin(), grado.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second < b.second;
            });

        int nodo_max_grado = max_it->first;

        // Agregar el nodo al recubrimiento
        recubrimiento.insert(nodo_max_grado);

        // Eliminar todas las aristas incidentes al nodo seleccionado
        aristas.erase(std::remove_if(aristas.begin(), aristas.end(),
            [&nodo_max_grado](const Arista& arista) {
                return arista.nodo1 == nodo_max_grado || arista.nodo2 == nodo_max_grado;
            }), aristas.end());

        // Actualizar los grados de los nodos restantes
        grado.clear();
        for (const Arista& arista : aristas) {
            grado[arista.nodo1]++;
            grado[arista.nodo2]++;
        }
    }

    return recubrimiento;
}

int main() {
    // Ejemplo de uso
    std::vector<Arista> aristas = { {1, 2}, {2, 3}, {2,5}, {3, 4}, {4, 1}, {1, 3},{4,5} };

    std::unordered_set<int> recubrimiento = recubrimientoGreedy(aristas);

    std::cout << "Recubrimiento: ";
    for (int nodo : recubrimiento) {
        std::cout << nodo << " ";
    }
    std::cout << std::endl;

    return 0;
}
