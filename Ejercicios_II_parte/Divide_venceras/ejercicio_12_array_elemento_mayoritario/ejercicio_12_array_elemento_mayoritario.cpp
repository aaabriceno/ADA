/*
Un array se dice que tiene un elemento mayoritario si más de la mitad de sus
elementos tienen el mismo valor. Dado un array A, nos proponen que diseñemos
un algoritmo eficiente que nos permita determinar sin un array tiene un elemento
mayoritario y, en caso afirmativo, identifique dicho elemento. Ahora bien, los
elementos del array no tienen por qué pertener a un dominio ordenado como el
de los números enteros y, por tanto, NO se pueden realizar comparaciones del
tipo A[i] > A[j]. En cualquier caso, sí que se pueden realizar comprobaciones del
tipo A[i] == A[j].
*/

#include <iostream>
#include <vector>

using namespace std;

// Función para contar la ocurrencia de un elemento en un rango del array
int countInRange(const vector<int>& nums, int num, int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

// Función para encontrar el elemento mayoritario en un rango del array
int findMajorityElementInRange(const vector<int>& nums, int low, int high) {
    if (low == high) {
        return nums[low];
    }

    // División del array
    int mid = low + (high - low) / 2;

    // Conquista
    int leftMajority = findMajorityElementInRange(nums, low, mid);
    int rightMajority = findMajorityElementInRange(nums, mid + 1, high);

    // Combinación
    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    int leftCount = countInRange(nums, leftMajority, low, high);
    int rightCount = countInRange(nums, rightMajority, low, high);

    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

// Función principal para encontrar el elemento mayoritario
int findMajorityElement(const vector<int>& nums) {
    int n = nums.size();

    // Llamar a la función auxiliar para encontrar el elemento mayoritario en todo el array
    int candidate = findMajorityElementInRange(nums, 0, n - 1);

    // Verificar si el candidato es realmente mayoritario
    int count = countInRange(nums, candidate, 0, n - 1);
    if (count > n / 2) {
        return candidate;
    }
    else {
        return -1; // No hay elemento mayoritario
    }
}

int main() {
    vector<int> array = { 1, 1, 1, 1, 2, 3, 2, 5,1,1};

    int majorityElement = findMajorityElement(array);

    if (majorityElement != -1) {
        cout << "El elemento mayoritario es: " << majorityElement << endl;
    }
    else {
        cout << "No hay elemento mayoritario en el array." << endl;
    }

    return 0;
}
