#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();  // Usar std::numeric_limits para INF

// Estructura para representar el grafo multietapa
struct GrafoMultietapa {
    int k; // Número de etapas
    std::vector<std::vector<int>> costos; // Matriz de costos
};

// Función para encontrar el camino de costo mínimo en un grafo multietapa
std::vector<int> CaminoCostoMinimoMultietapa(const GrafoMultietapa& G) {
    int k = G.k;
    int n = G.costos[0].size();  // Número de vértices en cada etapa (suponiendo que son iguales en todas las etapas)
    std::vector<std::vector<int>> tablaCostos(k, std::vector<int>(n, INF));
    std::vector<std::vector<int>> tablaDecisiones(k, std::vector<int>(n, -1));

    // Inicialización para la primera etapa
    tablaCostos[0][0] = 0; // El costo para el vértice origen es 0

    // Recorrido hacia adelante
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                if (G.costos[i - 1][l] != INF && tablaCostos[i - 1][l] != INF) {
                    int nuevoCosto = tablaCostos[i - 1][l] + G.costos[i - 1][j];
                    if (nuevoCosto < tablaCostos[i][j]) {
                        tablaCostos[i][j] = nuevoCosto;
                        tablaDecisiones[i][j] = l;
                    }
                }
            }
        }
    }

    // Recorrido hacia atrás para reconstruir el camino
    int indiceMinimo = 0;
    for (int i = 1; i < n; ++i) {
        if (tablaCostos[k - 1][i] < tablaCostos[k - 1][indiceMinimo]) {
            indiceMinimo = i;
        }
    }

    // Reconstruir el camino
    std::vector<int> camino;
    camino.push_back(indiceMinimo);

    for (int i = k - 1; i > 0; --i) {
        indiceMinimo = tablaDecisiones[i][indiceMinimo];
        camino.push_back(indiceMinimo);
    }

    std::reverse(camino.begin(), camino.end()); // Invertir el camino

    return camino;
}

int main() {
    // Ejemplo de uso
    GrafoMultietapa G;
    G.k = 5; // Número de etapas
    G.costos = {
        {0, 17, 8, 16, 20},
        {INF, 0, 12, 6, 15},
        {INF, INF, 0, 12, 16},
        {INF, INF, INF, 0, 15},
        {INF, INF, INF, INF, 0}
    };

    std::vector<int> caminoMinimo = CaminoCostoMinimoMultietapa(G);

    // Imprimir el camino de costo mínimo
    std::cout << "Camino de costo minimo: ";
    for (int i : caminoMinimo) {
        std::cout << i + 1 << " "; // Ajustar índices para imprimir
    }
    std::cout << std::endl;

    return 0;
}