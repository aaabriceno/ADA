/*
. Hemos decidido montar una empresa de desarrollo de software, para lo que
debemos adquirir n licencias, cuyo precio actual es de 100 € cada una. Sin
embargo, nuestro limitado presupuesto sólo nos permite adquirir una licencia
mensualmente. El problema es que, aunque ahora mismo todas las licencias nos
cuestan lo mismo (100€), el precio de la licencia i se incrementa mensualmente
un tanto por ciento ∆pi
. Esto es, dentro de k meses, la licencia i nos costará
100*(1+∆pi)
k
 euros. Sabiendo que, al final, necesitaremos tener todas las
licencias en regla, diseñe un algoritmo greedy que minimice el coste de
adquisición de las n licencias a partir de sus tasas de incremento de precio ∆pi
.
Obsérvese que el problema no se puede resolver de forma óptima con un
algoritmo greedy si, en vez de comprar licencias, nuestro objetivo fuese vender
equipos que se deprecien con el tiempo (∆pi<0).
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Licencia {
    int id;
    double tasaIncremento;

    Licencia(int i, double delta) : id(i), tasaIncremento(delta) {}
};

// Función de comparación para ordenar las licencias por tasaIncremento de forma ascendente
bool compararPorIncremento(const Licencia& a, const Licencia& b) {
    return a.tasaIncremento < b.tasaIncremento;
}

// Algoritmo Greedy para minimizar el coste de adquisición de las licencias
double costoMinimoLicencias(std::vector<Licencia>& licencias, int n) {
    std::sort(licencias.begin(), licencias.end(), compararPorIncremento);

    double costoTotal = 0.0;
    double factor = 1.0;

    for (int i = 0; i < n; ++i) {
        costoTotal += 100.0 * factor;
        factor *= (1.0 + licencias[i].tasaIncremento);
    }

    return costoTotal;
}

int main() {
    // Ejemplo de uso
    int n = 5; // Número de licencias
    std::vector<Licencia> licencias = { {1, 0.02}, {2, 0.01}, {3, 0.03}, {4, 0.05}, {5, 0.04} };

    double costoTotal = costoMinimoLicencias(licencias, n);

    std::cout << "Costo total minimo de adquisicion de las licencias: " << costoTotal << " euros\n";

    return 0;
}
