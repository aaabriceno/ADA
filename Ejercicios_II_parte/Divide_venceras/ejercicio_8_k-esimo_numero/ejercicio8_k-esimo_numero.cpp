/*
Diseñe un algoritmo "divide y vencerás" que permita calcular el k−ésimo menor
elemento de un vector
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}

// Función para encontrar el k-ésimo menor elemento usando la selección rápida
int k_esimo_numero(vector<int>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int partitionIndex = partition(arr, low, high);

        // Si el k-ésimo menor está en la partición izquierda
        if (partitionIndex - low == k - 1) {
            return arr[partitionIndex];
        }

        // Si el k-ésimo menor está en la partición derecha
        if (partitionIndex - low > k - 1) {
            return k_esimo_numero(arr, low, partitionIndex - 1, k);
        }

        // Si el k-ésimo menor está en la partición derecha
        return k_esimo_numero(arr, partitionIndex + 1, high, k - partitionIndex + low - 1);
    }

    // Si k no es válido
    return -1;
}

int main() {
    // Ejemplo de uso
    vector<int> arr = { 3, 8, 1, 6, 9, 10, 2, 11 };
    int k = 5; // Encuentra el quinto menor elemento

    int kthElement = k_esimo_numero(arr, 0, arr.size() - 1, k);

    cout << "El " << k << "-esimo menor elemento es: " << kthElement << endl;

    return 0;
}