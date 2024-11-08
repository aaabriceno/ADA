/*
Supongamos que tenemos k arrays ordenados, cada uno con n elementos, y
queremos combinarlos en un único array ordenado con kn elementos. Una
posible alternativa consiste en, utilizando un algoritmo clásico, mezclar los dos
primeros arrays, posteriormente mezclar el resultado con el tercero, y así
sucesivamente.
a. ¿Cuál sería el tiempo de ejecución de este algoritmo?
b. Diseñe un algoritmo de mezcla más eficiente.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergeTwoSortedArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i++]);
        }
        else {
            result.push_back(b[j++]);
        }
    }
    while (i < a.size()) {
        result.push_back(a[i++]);
    }
    while (j < b.size()) {
        result.push_back(b[j++]);
    }
    return result;
}

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays, int left, int right) {
    if (left == right) {
        return arrays[left];
    }
    int mid = left + (right - left) / 2;
    vector<int> leftHalf = mergeKSortedArrays(arrays, left, mid);
    vector<int> rightHalf = mergeKSortedArrays(arrays, mid + 1, right);
    return mergeTwoSortedArrays(leftHalf, rightHalf);
}

int main() {
    vector<vector<int>> arrays = {
        {1, 3, 5, 7, 9},
        {2, 4, 6, 8, 10},
        {0, 11, 12, 13, 14}
    };

    vector<int> result = mergeKSortedArrays(arrays, 0, arrays.size() - 1);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

// Función para combinar dos arrays ordenados
vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> result(n1 + n2);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copiar los elementos restantes de arr1, si los hay
    while (i < n1) {
        result[k++] = arr1[i++];
    }

    // Copiar los elementos restantes de arr2, si los hay
    while (j < n2) {
        result[k++] = arr2[j++];
    }

    return result;
}

// Función principal para combinar k arrays utilizando "divide y vencerás"
vector<int> mergeKArrays(const vector<vector<int>>& arrays, int start, int end) {
    if (start == end) {
        return arrays[start];
    }

    int mid = start + (end - start) / 2;

    // Recursivamente combinar las mitades izquierda y derecha
    vector<int> left = mergeKArrays(arrays, start, mid);
    vector<int> right = mergeKArrays(arrays, mid + 1, end);

    // Combinar las dos mitades
    return mergeArrays(left, right);
}

int main() {
    // Ejemplo de uso
    vector<vector<int>> arrays = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    int k = arrays.size();

    // Combinar los k arrays
    vector<int> result = mergeKArrays(arrays, 0, k - 1);

    
    cout << "Array combinado: "; // Imprimir el resultado combinado
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/