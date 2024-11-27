/*

Ejercicio Metodo Voraz 30/10/2024

*/

#include <iostream>
#include <vector>

using namespace std;

int maxMonedasDiferentes(const vector<int>& monedas) {
    int contador_monedas = 1;
    int suma = monedas[0];

    for (size_t i = 1; i < monedas.size(); i++) {
        if (monedas[i] > suma) {
            contador_monedas++;
            suma += monedas[i];
        }
    }
    return contador_monedas;
}

int main() {
    int pruebas;
    cout << "Ingrese la cantidad de pruebas: "; 
    cin >> pruebas;

    while (pruebas--) {
        int n;
        cout << "Ingrese la cantidad de monedas para las pruebas: "; 
        cin >> n;

        vector<int> monedas(n);

        for (int i = 0; i < n; i++) {
            cin >> monedas[i];
        }

        cout << maxMonedasDiferentes(monedas) << endl;
    }
    return 0;
}