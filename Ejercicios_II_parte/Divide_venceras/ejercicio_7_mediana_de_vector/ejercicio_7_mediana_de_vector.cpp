#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int encontrarMediana(vector<int>& arr, int izquierda, int derecha, int k);

int particionar(vector<int>& arr, int izquierda, int derecha, int pivote) {
    int valorPivote = arr[pivote];
    swap(arr[pivote], arr[derecha]);
    int almacenIndice = izquierda;
    for (int i = izquierda; i < derecha; i++) {
        if (arr[i] < valorPivote) {
            swap(arr[i], arr[almacenIndice]);
            almacenIndice++;
        }
    }
    swap(arr[almacenIndice], arr[derecha]);
    return almacenIndice;
}

int seleccionarPivote(vector<int>& arr, int izquierda, int derecha) {
    if (derecha - izquierda + 1 <= 5) {
        sort(arr.begin() + izquierda, arr.begin() + derecha + 1);
        return (izquierda + derecha) / 2;
    }

    for (int i = izquierda; i <= derecha; i += 5) {
        int subDerecha = min(i + 4, derecha);
        sort(arr.begin() + i, arr.begin() + subDerecha + 1);
        int mediana = (i + subDerecha) / 2;
        swap(arr[mediana], arr[izquierda + (i - izquierda) / 5]);
    }

    int mid = (derecha - izquierda) / 10 + izquierda + 1;
    return encontrarMediana(arr, izquierda, izquierda + (derecha - izquierda) / 5, mid);
}

int encontrarMediana(vector<int>& arr, int izquierda, int derecha, int k) {
    if (izquierda == derecha) {
        return arr[izquierda];
    }

    int pivoteIndice = seleccionarPivote(arr, izquierda, derecha);
    pivoteIndice = particionar(arr, izquierda, derecha, pivoteIndice);

    if (k == pivoteIndice) {
        return arr[k];
    }
    else if (k < pivoteIndice) {
        return encontrarMediana(arr, izquierda, pivoteIndice - 1, k);
    }
    else {
        return encontrarMediana(arr, pivoteIndice + 1, derecha, k);
    }
}

int main() {
    vector<int> arr = { 12, 4, 5, 7, 3, 8, 1,0 ,6,6,6,66, 9, 10, 2, 11,14,13,15,16 };

    int n = arr.size();
    int mediana = encontrarMediana(arr, 0, n - 1, n / 2);

    cout << "Mediana del vector: " << mediana << endl;

    return 0;
}



/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Función para dividir el vector en menores, iguales y mayores que el pivote
int partition(std::vector<int>& vec, int left, int right, int pivotIndex) {
    int pivotValue = vec[pivotIndex];
    std::swap(vec[pivotIndex], vec[right]); // Mover el pivote al final
    int storeIndex = left;

    for (int i = left; i < right; ++i) {
        if (vec[i] < pivotValue) {
            std::swap(vec[i], vec[storeIndex]);
            ++storeIndex;
        }
    }
    std::swap(vec[storeIndex], vec[right]); // Mover el pivote a su posición final
    return storeIndex;
}

// Función QuickSelect para encontrar el k-ésimo elemento más pequeño
int quickSelect(std::vector<int>& vec, int left, int right, int k) {
    if (left == right) return vec[left]; // Si el vector tiene un solo elemento

    // Elegir un pivote aleatorio
    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(vec, left, right, pivotIndex);

    if (k == pivotIndex) {
        return vec[k]; // El pivote está en la posición deseada
    } else if (k < pivotIndex) {
        return quickSelect(vec, left, pivotIndex - 1, k); // Buscar en la izquierda
    } else {
        return quickSelect(vec, pivotIndex + 1, right, k); // Buscar en la derecha
    }
}

// Función para encontrar la mediana
double encontrarMediana(std::vector<int>& vec) {
    int n = vec.size();
    if (n % 2 == 1) {
        // Si el tamaño es impar, buscar el elemento en la posición n/2
        return quickSelect(vec, 0, n - 1, n / 2);
    } else {
        // Si el tamaño es par, tomar el promedio de los elementos en las posiciones n/2 - 1 y n/2
        int mediana1 = quickSelect(vec, 0, n - 1, n / 2 - 1);
        int mediana2 = quickSelect(vec, 0, n - 1, n / 2);
        return (mediana1 + mediana2) / 2.0;
    }
}

int main() {
    srand(time(0)); // Inicializar la semilla para la elección aleatoria

    std::vector<int> vec = {7, 2, 1, 6, 8, 5, 3, 4,9};
    double mediana = encontrarMediana(vec);
    std::cout << "La mediana es: " << mediana << std::endl;

    return 0;
}

*/