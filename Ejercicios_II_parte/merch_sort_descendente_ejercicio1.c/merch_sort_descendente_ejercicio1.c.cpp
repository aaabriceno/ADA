/*
Ejercicio Algoritmo MerchSort 1c de forma descendente
Ordene el siguiente vector de numeros enteros
(9 1 3 5 0 4 2 6 8 7)
*/

#include <iostream>
#include <vector>
using namespace std;

void imprimirArray(const vector<int>& array, int izquierda, int derecha, const string& mensaje) {
    cout << mensaje << ": ";
    for (int i = izquierda; i <= derecha; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>& array, int izquierda, int medio, int derecha) {
    vector<int> array_izquierda(array.begin() + izquierda, array.begin() + medio + 1);
    vector<int> array_derecha(array.begin() + medio + 1, array.begin() + derecha + 1);

    int izq = 0, der = 0, k = izquierda;

    imprimirArray(array, izquierda, derecha, "Mezclando");

    while (izq < array_izquierda.size() && der < array_derecha.size()) {
        if (array_izquierda[izq] >= array_derecha[der]) {
            array[k++] = array_izquierda[izq++];
        }
        else {
            array[k++] = array_derecha[der++];
        }
    }
    while (izq < array_izquierda.size()) {
        array[k++] = array_izquierda[izq++];
    }
    while (der < array_derecha.size()) {
        array[k++] = array_derecha[der++];
    }

    imprimirArray(array, izquierda, derecha, "Resultado de mezcla");
}

void mergeSort(vector<int>& array, int izquierda, int derecha, int nivel = 0) {
    if (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;

        imprimirArray(array, izquierda, derecha, "Dividiendo");

        mergeSort(array, izquierda, medio, nivel + 1);
        mergeSort(array, medio + 1, derecha, nivel + 1);

        merge(array, izquierda, medio, derecha);
    }
}

int main() {
    vector<int> array = { 9, 1, 3, 5, 0, 4, 2, 6, 8, 7 };

    cout << "Array original: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(array, 0, array.size() - 1);

    cout << "Array ordenado: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
#include <iostream>

using namespace std;

void imprimirArray(int* leftPtr, int* rightPtr, const string& mensaje) {
    cout << mensaje << ": ";
    for (int* p = leftPtr; p <= rightPtr; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

void merge(int* leftPtr, int* midPtr, int* rightPtr) {
    int* leftEnd = midPtr;
    int* rightStart = midPtr + 1;
    int* tempArr = new int[rightPtr - leftPtr + 1];  // Arreglo temporal
    int* tempPtr = tempArr;

    imprimirArray(leftPtr, rightPtr, "Mezclando");

    // Mezcla los dos subarreglos en el arreglo temporal
    int* left = leftPtr;
    int* right = rightStart;
    while (left <= leftEnd && right <= rightPtr) {
        if (*left >= *right) {
            *tempPtr++ = *left++;
        } else {
            *tempPtr++ = *right++;
        }
    }

    // Copiar elementos restantes del lado izquierdo, si los hay
    while (left <= leftEnd) {
        *tempPtr++ = *left++;
    }

    // Copiar elementos restantes del lado derecho, si los hay
    while (right <= rightPtr) {
        *tempPtr++ = *right++;
    }

    // Copiar el arreglo temporal de nuevo al arreglo original
    tempPtr = tempArr;
    for (int* p = leftPtr; p <= rightPtr; p++) {
        *p = *tempPtr++;
    }

    imprimirArray(leftPtr, rightPtr, "Resultado de mezcla");

    delete[] tempArr;
}

void mergeSort(int* leftPtr, int* rightPtr) {
    if (leftPtr < rightPtr) {
        int* midPtr = leftPtr + (rightPtr - leftPtr) / 2;

        imprimirArray(leftPtr, rightPtr, "Dividiendo");

        // Dividir y ordenar la mitad izquierda
        mergeSort(leftPtr, midPtr);

        // Dividir y ordenar la mitad derecha
        mergeSort(midPtr + 1, rightPtr);

        // Mezclar las dos mitades ordenadas
        merge(leftPtr, midPtr, rightPtr);
    }
}

int main() {
    int arr[] = {9, 1, 3, 5, 0, 4, 2, 6, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, arr + size - 1);

    cout << "Array ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

*/