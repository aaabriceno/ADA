/*
Supongamos que un único camarero debe atender a n clientes de un restaurante
y atender al cliente i-ésimo requiere un tiempo ti
. La satisfacción de un cliente es
inversamente proporcional a su tiempo de espera y la propina que recibirá el
camarero dependerá de la satisfacción del cliente (si el cliente i espera wi
minutos, la propina que dará al camarero será pi=1/wi).
a. Diseñe un algoritmo greedy para maximizar las ganancias del camarero y
demuestre si el algoritmo diseñado devuelve siempre la solución óptima
[o encuentre un contraejemplo que muestre que no lo hace].
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Cliente {
    int id;
    int tiempoEspera;

    Cliente(int i, int t) : id(i), tiempoEspera(t) {}
};

bool compararPorTiempoEspera(const Cliente& a, const Cliente& b) {
    return a.tiempoEspera < b.tiempoEspera; // Ordenar de forma no decreciente por tiempo de espera
}

void maximizarGananciasCamarero(std::vector<Cliente>& clientes) {
    std::sort(clientes.begin(), clientes.end(), compararPorTiempoEspera);

    int gananciasTotales = 0;

    for (const Cliente& cliente : clientes) {
        gananciasTotales += 1 / static_cast<double>(cliente.tiempoEspera);
        std::cout << "Camarero atiende al cliente " << cliente.id << " con tiempo de espera " << cliente.tiempoEspera << std::endl;
    }

    std::cout << "Ganancias totales: " << gananciasTotales << std::endl;
}

int main() {
    // Ejemplo de uso
    std::vector<Cliente> clientes = { {1, 3}, {2, 1}, {3, 4}, {4, 6} };

    maximizarGananciasCamarero(clientes);

    return 0;
}