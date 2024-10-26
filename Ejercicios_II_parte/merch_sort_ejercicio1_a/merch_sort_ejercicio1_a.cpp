/*
Ejercicio Algoritmo MerchSort 1a
Ordene el siguiente vector de numeros enteros
(9 1 3 5 0 4 2 6 8 7)
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int>& array, int izquierda, int medio, int derecha) {
	vector<int> array_izquierda(array.begin() + izquierda, array.begin() + medio + 1);
	vector<int> array_derecha(array.begin() + medio + 1, array.begin() + derecha + 1);

	int izq = 0;
	int der = 0;
	int k = izquierda;
}