/*
#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Ingrese un numero: "; cin >> n;
	
	int i = 0;
	while (i <= n) {
		int k = i;
		while (k <= n) {
			k = k + 2;
		}
		k = 1;
		while (k <= i) {
			k = k+1;
		}
		i = i + 2;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese un numero: "; cin >> n;

    int i = 0;
    while (i <= n) {
        cout << "i = " << i << endl; // Muestra el valor de i en cada iteración del primer bucle

        int k = i;
        cout << "  Dentro del primer bucle while: k = " << k; // Muestra el valor inicial de k
        while (k <= n) {
            cout << " (k = " << k << ")"; // Muestra el valor de k en cada iteración
            k = k + 2;
        }
        cout << endl; // Salto de línea para claridad

        k = 1;
        cout << "  Dentro del segundo bucle while: k = " << k; // Muestra el valor inicial de k
        while (k <= i) {
            cout << " (k = " << k << ")"; // Muestra el valor de k en cada iteración
            k = k + 1;
        }
        cout << endl; // Salto de línea para claridad

        i = i + 2;
    }

    return 0;
}
