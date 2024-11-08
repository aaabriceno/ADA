// quick_sort_ejericicio1_b.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
/*
Ejercicio Algoritmo QuickSort 1.b 
Ordene el siguiente vector de numeros enteros
(9 1 3 5 0 4 2 6 8 7)
*/

#include <iostream>
#include <vector>
using namespace std;

int medianthree(int* ptr_izq, int* ptr_medio, int* ptr_der) {
	if ((*ptr_izq > *ptr_medio) != (*ptr_izq > *ptr_der)) {
		return *ptr_izq;
	}
	else if (*ptr_medio > *ptr_izq != *ptr_medio > *ptr_der) {
		return *ptr_medio;
	}
	else {
		return *ptr_der;
	}
}
int particion(int* ptr_izq, int* ptr_der) {
	int* ptr_medio = ptr_izq + (ptr_der - ptr_izq) / 2;
	int pivote_valor = medianthree(ptr_izq, ptr_medio, ptr_der);
	swap(*ptr_der, *ptr_medio);

	int pivote = *ptr_der;
	int* i = ptr_izq - 1;

	for (int* j = ptr_izq; j < ptr_der; j++) {
		if (*j < pivote) {
			i++;
			swap(*i, *j);
		}
	}
	swap(*(i + 1), *ptr_der);
	return(i + 1) - ptr_izq;
}

void quickSort(int* ptr_izq, int* ptr_der) {
	if (ptr_izq < ptr_der) {
		int pivoteIndex = particion(ptr_izq, ptr_der);
		quickSort(ptr_izq, ptr_izq + pivoteIndex - 1);
		quickSort(ptr_izq + pivoteIndex + 1, ptr_der);
	}
}

int main()
{
	vector<int> arr = { 9,1,3,5,0,4,2,6,8,7 };
	cout << "Array original: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	quickSort(&arr[0], &arr[arr.size() - 1]);
	cout << "Array ordenado: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}

 
