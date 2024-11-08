/*
Dado un vector de n elementos, de los cuales algunos están duplicados, diseñe
un algoritmo O(n log n) que permita eliminar todos los elementos duplicados.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para eliminar duplicados de un vector ordenado
static void remover_duplicados(vector<int>& sortedVector) {
    int n = sortedVector.size();

    // Caso base: vector vacío o con un solo elemento
    if (n <= 1) {
        return;
    }

    // Índice para almacenar elementos únicos
    int uniqueIndex = 0;

    // Iterar sobre el vector para eliminar duplicados adyacentes
    for (int i = 1; i < n; ++i) {
        // Si el elemento actual es diferente al anterior, lo almacenamos en la posición única
        if (sortedVector[i] != sortedVector[uniqueIndex]) {
            ++uniqueIndex;
            sortedVector[uniqueIndex] = sortedVector[i];
        }
    }

    // Redimensionar el vector para que solo contenga elementos únicos
    sortedVector.resize(uniqueIndex + 1);
}

// Función principal para eliminar duplicados de un vector
void eliminar_elementos_duplicados(vector<int>& inputVector) {
    // Ordenar el vector
    sort(inputVector.begin(), inputVector.end());

    // Eliminar duplicados
    remover_duplicados(inputVector);
}

int main() {
    vector<int> inputVector = { 3,3,3,3,3,3,3,3,111,111,11111,2,3,4,5,653, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    cout << "Vector original:\n";
    for (int num : inputVector) {
        cout << num << " ";
    }
    cout << "\n";

    // Eliminar duplicados
    eliminar_elementos_duplicados(inputVector);

    cout << "Vector sin duplicados:\n";
    for (int num : inputVector) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}