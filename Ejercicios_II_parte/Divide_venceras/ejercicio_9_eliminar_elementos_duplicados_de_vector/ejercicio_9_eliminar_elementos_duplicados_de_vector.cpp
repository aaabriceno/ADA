#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Función para combinar dos vectores eliminando duplicados
vector<int> mergeAndRemoveDuplicates(const vector<int>& left, const vector<int>& right) {
    unordered_set<int> uniqueElements;
    vector<int> result;

    for (int num : left) {
        uniqueElements.insert(num);
    }
    for (int num : right) {
        uniqueElements.insert(num);
    }

    for (int num : uniqueElements) {
        result.push_back(num);
    }

    sort(result.begin(), result.end());
    return result;
}

// Función recursiva para dividir el vector y eliminar duplicados
vector<int> divideAndConquerRemoveDuplicates(const vector<int>& inputVector, int start, int end) {
    if (start == end) {
        return { inputVector[start] };
    }

    int mid = start + (end - start) / 2;
    vector<int> left = divideAndConquerRemoveDuplicates(inputVector, start, mid);
    vector<int> right = divideAndConquerRemoveDuplicates(inputVector, mid + 1, end);

    return mergeAndRemoveDuplicates(left, right);
}

// Función principal para eliminar duplicados de un vector
void eliminar_elementos_duplicados(vector<int>& inputVector) {
    if (inputVector.empty()) {
        return;
    }

    vector<int> result = divideAndConquerRemoveDuplicates(inputVector, 0, inputVector.size() - 1);
    inputVector = result;
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
