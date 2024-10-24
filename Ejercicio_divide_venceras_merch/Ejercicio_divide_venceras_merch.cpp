#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir el array
void print_array(const vector<int>& arr, int left, int right) {
    cout << "[ ";
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]";
}

// Función que mezcla dos subarrays y cuenta las inversiones cruzadas
int merge_and_count(vector<int>& arr, int left, int mid, int right) {
    // Crear subarrays temporales para las dos mitades
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;  // Índice para el subarray izquierdo
    int j = 0;  // Índice para el subarray derecho
    int k = left;  // Índice para el array combinado original
    int inversions = 0;

    // Comparamos y contamos las inversiones
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
            // Si el elemento de la derecha es menor, cuenta como inversión
            inversions += leftArr.size() - i;
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
    cout << " | Inversiones cruzadas: " << inversions << endl;

    return inversions;
}

// Función recursiva para dividir el array y contar las inversiones
int sort_and_count(vector<int>& arr, int left, int right) {
    int inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Imprimir la partición actual
        cout << "Partición: ";
        print_array(arr, left, right);
        cout << endl;

        // Contar las inversiones en la mitad izquierda
        inversions += sort_and_count(arr, left, mid);
        // Contar las inversiones en la mitad derecha
        inversions += sort_and_count(arr, mid + 1, right);
        // Contar las inversiones cruzadas
        inversions += merge_and_count(arr, left, mid, right);
    }

    return inversions;
}

int main() {
    vector<int> arr = { 3,7,10,14,18,19,2,11,16,17,23,25 };  // Ejemplo de ranking A y B combinados

    cout << "Array original: ";
    print_array(arr, 0, arr.size() - 1);
    cout << endl << endl;

    int total_inversions = sort_and_count(arr, 0, arr.size() - 1);

    cout << "\nNúmero total de inversiones: " << total_inversions << endl;

    return 0;
}
