/*
#include <iostream>
#include <vector>

using namespace std;

void print_array(const vector<int>& arr, int left, int right) { //imprime el array
    cout << "[ ";
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]";
}

int merge_and_count(vector<int>& arr, int left, int mid, int right) {
    // Crear subarrays temporales para las dos mitades
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;     // Índice subarray izquierdo
    int j = 0;     // Índice subarray derecho
    int k = left;  // Índice array combinado original
    int inversiones = 0;

    // Comparamos y contamos las inversiones
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
            // Si el elemento de la derecha es menor, cuenta como inversión
            inversiones += leftArr.size() - i;
        }
    }

    // Copiamos los elementos restantes de ambas mitades
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }

    // Imprimir el estado después de la combinación
    cout << "Combinando: ";
    print_array(arr, left, right);
    cout << " | Inversiones cruzadas: " << inversiones << endl;

    return inversiones;
}

// Función recursiva para dividir el array y contar las inversiones
int sort_and_count(vector<int>& arr, int left, int right) {
    int inversiones = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Imprimir la partición actual
        cout << "Partición: ";
        print_array(arr, left, right);
        cout << endl;

        // Contar las inversiones en la mitad izquierda
        inversiones += sort_and_count(arr, left, mid);
        // Contar las inversiones en la mitad derecha
        inversiones += sort_and_count(arr, mid + 1, right);
        // Contar las inversiones cruzadas
        inversiones += merge_and_count(arr, left, mid, right);
    }

    return inversiones;
}

int main() {
    vector<int> arr = { 3,7,10,14,18,19,2,11,16,17,23,25 };

    cout << "Array original: ";
    print_array(arr, 0, arr.size() - 1);
    cout << endl << endl;

    int total_inversiones = sort_and_count(arr, 0, arr.size() - 1);

    cout << "\nNúmero total de inversiones: " << total_inversiones << endl;

    return 0;
}
*/

//Comparacion de preferencias

#include <iostream>
#include <vector>

using namespace std;

int merge_and_count(vector<int>& arr, int left, int mid, int right) {

    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;  // Índice subarray izquierdo
    int j = 0;  // Índice subarray derecho
    int k = left;  // Índice combinado original
    int inversiones = 0;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversiones += leftArr.size() - i;
        }
    }

    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }

    return inversiones;
}

int sort_and_count(vector<int>& arr, int left, int right) {
    int inversiones = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inversiones += sort_and_count(arr, left, mid);  
        inversiones += sort_and_count(arr, mid + 1, right);
        inversiones += merge_and_count(arr, left, mid, right);
    }

    return inversiones;
}

int main() {
    cout << "Array original: 3 7 10 14 18 19 2 11 16 17 23 25\n\n";
    vector<int> arr = { 3, 7, 10, 14, 18, 19, 2, 11, 16, 17, 23, 25 };

    int total_inversiones = sort_and_count(arr, 0, arr.size() - 1);

    cout << "Numero total de inversiones: " << total_inversiones << endl;

    return 0;
}


