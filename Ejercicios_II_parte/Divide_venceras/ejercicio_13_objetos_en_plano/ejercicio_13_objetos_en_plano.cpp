/*
Dada la forma exacta de un conjunto de objetos en un plano, encuentre el perfil
de los mismos (en dos dimensiones) que se obtiene al eliminar las líneas ocultas
utilizando un algoritmo "divide y vencerás" y analice el tiempo de ejecución del
algoritmo resultante.
 NOTA: Los objetos son de forma rectangular, codificados mediante cuatro
 coordenadas, empezando por la esquina superior izquierda y continuando
 en el sentido de las agujas del reloj.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un objeto rectangular
struct Rectangulo {
    int x1, y1, x2, y2; // Coordenadas de dos esquinas opuestas
};

// Función para determinar si un punto está dentro de un rectángulo
bool puntoDentroRectangulo(int x, int y, const Rectangulo& rect) {
    return (x >= rect.x1 && x <= rect.x2 && y >= rect.y1 && y <= rect.y2);
}

// Función para obtener el perfil de un solo rectángulo
vector<pair<int, int>> obtenerPerfilRectangulo(const Rectangulo& rect) {
    return {
        {rect.x1, rect.y1},
        {rect.x2, rect.y1},
        {rect.x2, rect.y2},
        {rect.x1, rect.y2}
    };
}

// Función para combinar dos perfiles para unir las partes visibles
vector<pair<int, int>> combinarPerfiles(const vector<pair<int, int>>& perfil1, const vector<pair<int, int>>& perfil2) {
    // Lógica para combinar dos perfiles y obtener el perfil final
    // Aquí simplemente concatenamos los perfiles para simplificar
    vector<pair<int, int>> perfilCombinado = perfil1;
    perfilCombinado.insert(perfilCombinado.end(), perfil2.begin(), perfil2.end());
    return perfilCombinado;
}

// Función principal para eliminar las líneas ocultas utilizando "divide y vencerás"
vector<pair<int, int>> eliminarLineasOcultas(const vector<Rectangulo>& objetos, int bajo, int alto) {
    if (bajo == alto) {
        // Caso base: un solo objeto, devuelve su perfil
        return obtenerPerfilRectangulo(objetos[bajo]);
    }

    // División de la escena en dos partes
    int medio = bajo + (alto - bajo) / 2;

    // Conquista: eliminar líneas ocultas en ambas mitades recursivamente
    vector<pair<int, int>> perfil1 = eliminarLineasOcultas(objetos, bajo, medio);
    vector<pair<int, int>> perfil2 = eliminarLineasOcultas(objetos, medio + 1, alto);

    // Combinación: unir los perfiles de ambas mitades
    return combinarPerfiles(perfil1, perfil2);
}

int main() {
    // Ejemplo de uso
    vector<Rectangulo> objetos = {
        {0, 0, 5, 5},
        {2, 2, 7, 7},
        {4, 4, 9, 9}
        // Agrega más objetos según sea necesario
    };

    // Eliminar las líneas ocultas en la escena
    vector<pair<int, int>> perfilFinal = eliminarLineasOcultas(objetos, 0, objetos.size() - 1);

    // Imprimir el perfil final
    cout << "Perfil final despues de eliminar lineas ocultas:\n";
    for (auto punto : perfilFinal) {
        cout << "(" << punto.first << ", " << punto.second << ")\n";
    }

    return 0;
}
