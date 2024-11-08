/*
Se tiene un buque mercante cuya capacidad de carga es de k toneladas y un
conjunto de contenedores c1, …, cn cuyos pesos respectivos son p1, …, pn
(expresados también en toneladas). Teniendo en cuenta que la capacidad del
buque es menor que la suma total de los pesos de los contenedores:

b. Diseñe un algoritmo que intente maximizar el número de toneladas cargadas.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Contenedor {
    int id;
    double peso;

    Contenedor(int i, double p) : id(i), peso(p) {}
};

bool compararPorPeso(const Contenedor& a, const Contenedor& b) {
    return a.peso > b.peso; // Ordenar de forma no creciente (mayor a menor)
}

void maximizarToneladas(std::vector<Contenedor>& contenedores, double capacidadBuque) {
    std::sort(contenedores.begin(), contenedores.end(), compararPorPeso);

    double pesoCargado = 0.0;
    int contenedoresCargados = 0;

    std::cout << "Intentando cargar contenedores en el buque con capacidad de " << capacidadBuque << " toneladas." << std::endl;

    for (const Contenedor& contenedor : contenedores) {
        if (pesoCargado + contenedor.peso <= capacidadBuque) {
            pesoCargado += contenedor.peso;
            contenedoresCargados++;
            std::cout << "Contenedor " << contenedor.id << " cargado: " << contenedor.peso << " toneladas." << std::endl;
        }
    }

    std::cout << "Total de contenedores cargados: " << contenedoresCargados << std::endl;
    std::cout << "Peso total cargado: " << pesoCargado << " toneladas." << std::endl;
}

int main() {
    double capacidadBuque = 20.0;
    std::vector<Contenedor> contenedores = { {1, 12.0}, {2, 2.5}, {3, 1.5}, {4, 14.0}, {5, 2.3}, {6, 4.6}, {7, 3.9}, {8, 1.2}, {9, 0.7} };

    maximizarToneladas(contenedores, capacidadBuque);

    return 0;
}
