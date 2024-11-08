/*
Dado un vector ordenado de números enteros X, diseñe un algoritmo "divide y
vencerás" que permita determinar si existe un índice i tal que X[i] = i.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función auxiliar para buscar si hay un índice i tal que X[i] = i
int buscarIndiceIgualValor(const vector<int>& X, int bajo, int alto) {
    if (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;

        // Verificar si X[medio] es igual a medio
        if (X[medio] == medio) {
            return medio; // Encontramos un índice que cumple la condición
        }
        else if (X[medio] > medio) {
            // Si X[medio] es mayor que medio, la solución está en la mitad izquierda
            return buscarIndiceIgualValor(X, bajo, medio - 1);
        }
        else {
            // Si X[medio] es menor que medio, la solución está en la mitad derecha
            return buscarIndiceIgualValor(X, medio + 1, alto);
        }
    }

    // Si no encontramos ningún índice que cumpla la condición
    return -1;
}

int main() {
    vector<int> X = { 2, 0, 7, 8, 9, 5, 12, 17 }; // Vector desordenado
    cout << "Vector original:" << endl;
    for (int i = 0; i < X.size(); i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    sort(X.begin(), X.end());
    cout << "Vector ordenado:" << endl;
    for (int i = 0; i < X.size(); i++) {
        cout << X[i] << " ";
    }

    int resultado = buscarIndiceIgualValor(X, 0, X.size() - 1);

    if (resultado != -1) {
        cout << "\nExiste un indice i = " << resultado << " tal que X[i] = i." << endl;
    }
    else {
        cout << "\nNo existe ningun indice i tal que X[i] = i." << endl;
    }

    return 0;
}
