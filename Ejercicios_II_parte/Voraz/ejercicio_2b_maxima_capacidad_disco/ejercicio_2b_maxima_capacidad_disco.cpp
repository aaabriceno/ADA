/*
Sean n programas P1, ..., Pn que hay que almacenar en un disco. El programa Pi
requiere Si
 megabytes de espacio y la capacidad del disco es D megabytes,
siendo D < ΣSi
. Resuelva las siguientes cuestiones:
b. Diseñe un algoritmo greedy que intente aprovechar al máximo la
capacidad del disco (demuestre que podemos utilizar un algoritmo
greedy que seleccione los programas por orden no creciente para obtener
la solución exacta o encuentre un contraejemplo de lo contrario).
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Programa {
    int id;
    int espacio;

    Programa(int i, int s) : id(i), espacio(s) {}
};

bool compararPorEspacio(const Programa& a, const Programa& b) {
    return a.espacio > b.espacio; // Ordenar de forma no creciente
}

void aprovecharMaximo(std::vector<Programa>& programas, int capacidadDisco) {
    std::sort(programas.begin(), programas.end(), compararPorEspacio);

    int espacioUsado = 0;
    int programasAlmacenados = 0;

    for (const Programa& programa : programas) {
        if (espacioUsado + programa.espacio <= capacidadDisco) {
            espacioUsado += programa.espacio;
            programasAlmacenados++;
            std::cout << "Programa " << programa.id << " almacenado con capacidad " << programa.espacio << " MB." << std::endl;
        }
    }

    std::cout << "Total de programas almacenados: " << programasAlmacenados << std::endl;
}

int main() {
    // Ejemplo de uso
    int capacidadDisco = 15;
    std::vector<Programa> programas = { {1, 5}, {2, 8}, {3, 3}, {4, 6} };

    aprovecharMaximo(programas, capacidadDisco);

    return 0;
}
