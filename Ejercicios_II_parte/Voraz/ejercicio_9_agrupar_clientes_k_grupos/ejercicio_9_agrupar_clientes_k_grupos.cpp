/*
El departamento de marketing de nuestra empresa desea segmentar nuestro
conjunto de clientes en K grupos para diseñar campañas de marketing dirigidas a
cada grupo por separado. Si suponemos que podemos caracterizar a cada cliente
mediante un vector de características (c1, .., cn) y medir la similitud entre dos
clientes como la inversa de la distancia entre sus vectores de características,
diseñe un algoritmo greedy que nos permita agrupar a nuestros clientes en K
grupos diferentes de tal forma que se maximice la distancia entre clientes de
distintos grupos.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <random>

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

struct Cliente {
    int id;
    std::vector<double> caracteristicas;

    Cliente(int i, const std::vector<double>& feats) : id(i), caracteristicas(feats) {}
};

// Función para calcular la distancia euclidiana entre dos vectores de características
double calcularDistancia(const std::vector<double>& v1, const std::vector<double>& v2) {
    double distancia = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        distancia += std::pow(v1[i] - v2[i], 2);
    }
    return std::sqrt(distancia);
}

// Función para encontrar el cliente más lejano de un conjunto dado de centroides
int encontrarClienteMasLejano(const std::vector<Cliente>& clientes, const std::vector<int>& centroides) {
    double distanciaMaxima = -1.0;
    int clienteMasLejano = -1;

    for (size_t i = 0; i < clientes.size(); ++i) {
        double distanciaMinima = std::numeric_limits<double>::max();

        // Calcular la distancia al grupo más cercano
        for (int centroideId : centroides) {
            double distancia = calcularDistancia(clientes[i].caracteristicas, clientes[centroideId].caracteristicas);
            distanciaMinima = std::min(distanciaMinima, distancia);
        }

        if (distanciaMinima > distanciaMaxima) {
            distanciaMaxima = distanciaMinima;
            clienteMasLejano = i;
        }
    }
    return clienteMasLejano;
}

// Algoritmo Greedy para maximizar la distancia entre los grupos
std::vector<std::vector<int>> agruparClientesGreedy(const std::vector<Cliente>& clientes, int k) {
    std::vector<std::vector<int>> grupos(k);
    std::vector<int> centroides;

    // Seleccionar los primeros k clientes aleatoriamente como centroides
    for (int i = 0; i < k; ++i) {
        centroides.push_back(i);
        grupos[i].push_back(i);
    }

    // Asignar clientes al grupo más lejano de los centroides actuales
    for (size_t i = k; i < clientes.size(); ++i) {
        int grupoMasLejano = encontrarClienteMasLejano(clientes, centroides);
        centroides.push_back(grupoMasLejano);
        grupos[grupoMasLejano % k].push_back(grupoMasLejano);
    }

    return grupos;
}

int main() {
    // Ejemplo de uso
    std::vector<Cliente> clientes = {
        {1, {1.0, 2.0}},
        {2, {2.0, 3.0}},
        {3, {5.0, 8.0}},
        {4, {7.0, 6.0}},
        {5, {10.0, 12.0}}
    };

    int k = 2;  // Número de grupos

    std::vector<std::vector<int>> grupos = agruparClientesGreedy(clientes, k);

    // Imprimir resultados
    std::cout << "Grupos resultantes:\n";
    for (int i = 0; i < k; ++i) {
        std::cout << "Grupo " << i + 1 << ": ";
        for (int clienteId : grupos[i]) {
            std::cout << "Cliente " << clienteId + 1 << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
