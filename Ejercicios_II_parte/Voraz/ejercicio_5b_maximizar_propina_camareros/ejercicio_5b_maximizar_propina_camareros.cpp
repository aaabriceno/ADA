/*
Supongamos que un único camarero debe atender a n clientes de un restaurante
y atender al cliente i-ésimo requiere un tiempo ti
. La satisfacción de un cliente es
inversamente proporcional a su tiempo de espera y la propina que recibirá el
camarero dependerá de la satisfacción del cliente (si el cliente i espera wi
minutos, la propina que dará al camarero será pi=1/wi).

b. Nuestro restaurante toma la decisión de contratar a más camareros para
reducir el tiempo de espera de sus clientes. Modifique el algoritmo
anterior para maximizar las propinas de k camareros.
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

void maximizarPropinasConCamareros(std::vector<Cliente>& clientes, int k) {
    std::sort(clientes.begin(), clientes.end(), compararPorTiempoEspera);

    std::vector<int> tiempoAsignado(k, 0); // Tiempo asignado a cada camarero
    double propinaTotal = 0.0;

    for (const Cliente& cliente : clientes) {
        int camarero = std::min_element(tiempoAsignado.begin(), tiempoAsignado.end()) - tiempoAsignado.begin();
        tiempoAsignado[camarero] += cliente.tiempoEspera;

        double propina = 1.0 / tiempoAsignado[camarero];
        propinaTotal += propina;

        std::cout << "Camarero " << camarero + 1 << " atiende al cliente " << cliente.id << " con tiempo de espera " << cliente.tiempoEspera << " y propina " << propina << std::endl;
    }

    std::cout << "Propina total: " << propinaTotal << std::endl;
}

int main() {
    // Ejemplo de uso
    std::vector<Cliente> clientes = { {1, 5}, {2, 2}, {3, 8}, {4, 1} };
    int k = 2; // Número de camareros

    maximizarPropinasConCamareros(clientes, k);

    return 0;
}
