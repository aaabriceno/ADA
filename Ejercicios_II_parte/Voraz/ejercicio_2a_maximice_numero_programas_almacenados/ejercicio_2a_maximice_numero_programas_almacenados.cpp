/*
Sean n programas P1, ..., Pn que hay que almacenar en un disco. El programa Pi
requiere Si
 megabytes de espacio y la capacidad del disco es D megabytes,
siendo D < ΣSi
. Resuelva las siguientes cuestiones:
a. Diseñe un algoritmo greedy que maximice el número de programas
	almacenados en el disco (existe un algoritmo que proporciona una
	solución óptima).
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
    return a.espacio < b.espacio; // Ordenar de forma no decreciente
}

void maximizarProgramas(std::vector<Programa>& programas, int capacidadDisco) {
    std::sort(programas.begin(), programas.end(), compararPorEspacio);

    int espacioUsado = 0;
    int programasAlmacenados = 0;

    for (const Programa& programa : programas) {
        if (espacioUsado + programa.espacio <= capacidadDisco) {
            espacioUsado += programa.espacio;
            programasAlmacenados++;
            std::cout << "Programa " << programa.id << " almacenado." << std::endl;
        }
    }

    std::cout << "Total de programas almacenados: " << programasAlmacenados << std::endl;
}

int main() {
    // Ejemplo de uso
    int capacidadDisco = 15;
    std::vector<Programa> programas = { {1, 5}, {2, 8}, {3, 3}, {4, 6} };

    maximizarProgramas(programas, capacidadDisco);

    return 0;
}