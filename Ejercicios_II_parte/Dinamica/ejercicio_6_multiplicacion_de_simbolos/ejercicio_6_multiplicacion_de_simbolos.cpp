#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool evaluarExpresion(const std::string& x, const std::unordered_map<char, std::unordered_map<char, char>>& tablaMultiplicacion) {
    int n = x.size();

    // Matriz de memorización: cada celda [i][j] almacena un conjunto de resultados posibles
    std::vector<std::vector<std::unordered_set<char>>> memo(n, std::vector<std::unordered_set<char>>(n));

    // Llenar la diagonal principal con los valores iniciales de los caracteres de la cadena
    for (int i = 0; i < n; ++i) {
        memo[i][i].insert(x[i]);
    }

    // Llenar la matriz para subexpresiones de longitud creciente
    for (int longitud = 2; longitud <= n; ++longitud) {
        for (int i = 0; i <= n - longitud; ++i) {
            int j = i + longitud - 1;

            // Verificar todas las particiones posibles en [i, j]
            for (int k = i; k < j; ++k) {
                for (char a : memo[i][k]) {
                    for (char b : memo[k + 1][j]) {
                        // Obtener el resultado de multiplicar 'a' y 'b' usando la tabla
                        if (tablaMultiplicacion.count(a) && tablaMultiplicacion.at(a).count(b)) {
                            memo[i][j].insert(tablaMultiplicacion.at(a).at(b));
                        }
                    }
                }
            }
        }
    }

    // Comprobar si 'a' está en los resultados posibles para toda la cadena
    return memo[0][n - 1].count('a') > 0;
}

int main() {
    // Tabla de multiplicación basada en la imagen proporcionada
    std::unordered_map<char, std::unordered_map<char, char>> tablaMultiplicacion = {
        {'a', {{'a', 'b'}, {'b', 'b'}, {'c', 'a'}}},
        {'b', {{'a', 'c'}, {'b', 'b'}, {'c', 'a'}}},
        {'c', {{'a', 'a'}, {'b', 'c'}, {'c', 'c'}}}
    };

    // Cadena de entrada
    std::string x = "ccccca";

    // Evaluar la expresión
    bool esPosible = evaluarExpresion(x, tablaMultiplicacion);

    // Imprimir el resultado
    if (esPosible) {
        std::cout << "Es posible poner parentesis en la expresion para obtener 'a'.\n";
    }
    else {
        std::cout << "No es posible obtener 'a' mediante la colocacion de paréntesis en la expresion.\n";
    }

    return 0;
}
