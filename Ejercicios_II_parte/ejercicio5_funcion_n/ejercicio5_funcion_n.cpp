/*
Ejercicion 5 ¿Cuántas líneas, en función de n, 
imprime el siguiente programa? 
*/

#include <iostream>
using namespace std;
int contador = 0;

void f(int n) {
    if (n > 1) {
		
        cout << "Linea...\n";
		contador++;
		f(n / 2);
		f(n / 2);
    }
}

int main()
{
	int n;
	cout << "Ingrese n: "; cin >> n;
	f(n);
	cout << "Cantidad de lineas: " << contador << endl;
	return 0;
}

/*
se imprime 2^(log(base 2)n) - 1 lineas, el log se redondea al numero entero menor
*/