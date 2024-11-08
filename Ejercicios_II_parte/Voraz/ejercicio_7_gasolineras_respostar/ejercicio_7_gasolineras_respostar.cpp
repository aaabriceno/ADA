/*
Un autobús realiza una ruta determinada entre dos ciudades. Con el tanque de
gasolina lleno, el autobús puede recorrer n kilómetros sin parar. El conductor
dispone de un mapa de carreteras que le indica las gasolineras que hay en su
ruta. Para minimizar el tiempo empleado en recorrer su ruta, el conductor desea
pararse a repostar el menor número posible de veces. Diseñe un algoritmo
greedy que determine en qué gasolineras tiene que repostar y demuestre que su
algoritmo encuentra siempre la solución óptima.
*/
#include <iostream>
#include <vector>

struct Gasolinera {
    int distancia;
    int capacidad;

    Gasolinera(int d, int c) : distancia(d), capacidad(c) {}
};

// Función para determinar en qué gasolineras repostar
std::vector<int> seleccionarGasolineras(const std::vector<Gasolinera>& gasolineras, int autonomia) {
    std::vector<int> gasolinerasSeleccionadas;
    int distanciaRecorrida = 0;
    int ultimaParada = 0;
    int i = 0;
    int n = gasolineras.size();

    while (i < n) {
        int maxDistancia = distanciaRecorrida + autonomia;
        // Buscar la gasolinera más lejana dentro del rango de autonomía actual
        int mejorGasolinera = -1;

        while (i < n && gasolineras[i].distancia <= maxDistancia) {
            mejorGasolinera = i;
            i++;
        }

        // Si no hay gasolinera dentro del rango, no se puede continuar
        if (mejorGasolinera == -1) break;

        // Repostar en la gasolinera más lejana encontrada
        gasolinerasSeleccionadas.push_back(gasolineras[mejorGasolinera].distancia);
        distanciaRecorrida = gasolineras[mejorGasolinera].distancia;
    }

    return gasolinerasSeleccionadas;
}

int main() {
    // Ejemplo de uso
    std::vector<Gasolinera> gasolineras = { {100, 50}, {200, 20}, {300, 60}, {400, 30}, {500, 25} };
    int autonomia = 150;

    std::vector<int> gasolinerasSeleccionadas = seleccionarGasolineras(gasolineras, autonomia);

    std::cout << "Repostar en las gasolineras en las siguientes distancias:\n";
    for (int distancia : gasolinerasSeleccionadas) {
        std::cout << distancia << " ";
    }
    std::cout << "\n";

    return 0;
}
