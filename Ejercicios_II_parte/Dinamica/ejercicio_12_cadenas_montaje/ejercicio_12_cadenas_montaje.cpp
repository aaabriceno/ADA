#include <iostream>
#include <vector>
#include <algorithm>

// Estructura para representar las cadenas de montaje
struct CadenaMontaje {
    int n; // Número de estaciones
    std::vector<int> tiempos;       // Tiempos en cada estación
    std::vector<int> tiemposCambio; // Tiempos de cambio entre cadenas
    int tiempoEntrada;              // Tiempo de entrada
    int tiempoSalida;               // Tiempo de salida
};

// Función para encontrar la ruta óptima
std::vector<int> RutaOptima(const CadenaMontaje& cadena1, const CadenaMontaje& cadena2) {
    int n = cadena1.n;

    // Matrices de costos acumulados y rutas
    std::vector<std::vector<int>> costos(2, std::vector<int>(n, 0));
    std::vector<std::vector<int>> rutas(2, std::vector<int>(n, -1));

    // Inicializar los costos para la primera estación
    costos[0][0] = cadena1.tiempoEntrada + cadena1.tiempos[0];
    costos[1][0] = cadena2.tiempoEntrada + cadena2.tiempos[0];

    // Rellenar las matrices de costos y rutas
    for (int j = 1; j < n; ++j) {
        // Costos para la cadena 1
        int costoPermanecer1 = costos[0][j - 1] + cadena1.tiempos[j];
        int costoCambiarA1 = costos[1][j - 1] + cadena2.tiemposCambio[j] + cadena1.tiempos[j];

        if (costoPermanecer1 <= costoCambiarA1) {
            costos[0][j] = costoPermanecer1;
            rutas[0][j] = 0; // Permanecer en cadena 1
        }
        else {
            costos[0][j] = costoCambiarA1;
            rutas[0][j] = 1; // Cambiar desde cadena 2 a 1
        }

        // Costos para la cadena 2
        int costoPermanecer2 = costos[1][j - 1] + cadena2.tiempos[j];
        int costoCambiarA2 = costos[0][j - 1] + cadena1.tiemposCambio[j] + cadena2.tiempos[j];

        if (costoPermanecer2 <= costoCambiarA2) {
            costos[1][j] = costoPermanecer2;
            rutas[1][j] = 1; // Permanecer en cadena 2
        }
        else {
            costos[1][j] = costoCambiarA2;
            rutas[1][j] = 0; // Cambiar desde cadena 1 a 2
        }
    }

    // Encontrar el menor tiempo total
    int costoFinalCadena1 = costos[0][n - 1] + cadena1.tiempoSalida;
    int costoFinalCadena2 = costos[1][n - 1] + cadena2.tiempoSalida;

    std::vector<int> rutaOptima;

    int actualCadena = (costoFinalCadena1 <= costoFinalCadena2) ? 0 : 1;
    rutaOptima.push_back(actualCadena);

    // Construir la ruta óptima hacia atrás
    for (int j = n - 1; j > 0; --j) {
        actualCadena = rutas[actualCadena][j];
        rutaOptima.push_back(actualCadena);
    }

    std::reverse(rutaOptima.begin(), rutaOptima.end());
    return rutaOptima;
}

int main() {
    // Datos de las líneas de ensamblaje
    CadenaMontaje cadena1 = { 6, {7, 9, 3, 4, 8, 4}, {0, 2, 3, 1, 3, 4}, 2, 3 };
    CadenaMontaje cadena2 = { 6, {8, 5, 6, 4, 5, 7}, {0, 2, 1, 2, 2, 1}, 4, 2 };

    // Encontrar la ruta óptima
    std::vector<int> rutaOptima = RutaOptima(cadena1, cadena2);

    // Imprimir la ruta óptima
    std::cout << "Ruta optima: ";
    for (int i : rutaOptima) {
        std::cout << (i + 1) << " "; // Mostrar como cadena 1 o 2
    }
    std::cout << std::endl;

    return 0;
}
