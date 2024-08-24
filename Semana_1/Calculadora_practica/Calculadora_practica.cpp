/*
#include <iostream>
using namespace std;

float Adicion(float a, float b) {
    return a + b;
}

float Sustraccion(float a, float b) {
    return a - b;
}

float Multiplicacion(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        cout << "No se puedo una division por cero!" << endl;
        return 0;
    }
}

int main() {
    float a, b, c;
    int opt;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    cout << "Ingresa la opcion (0-Adicion, 1-Sustraccion, 2-Multiplicacion, 3-Division): ";
    cin >> opt;

    switch (opt) {
    case 0: c = Adicion(a, b); break;
    case 1: c = Sustraccion(a, b); break;
    case 2: c = Multiplicacion(a, b); break;
    case 3: c = Division(a, b); break;
    default: cout << "Opcion invalida" << endl; return 1;
    }

    cout << "Resultado: " << c << endl;
    return 0;
}
*/


#include <iostream>
using namespace std;

float Adicion(float a, float b) {
    return a + b;
}

float Sustraccion(float a, float b) {
    return a - b;
}

float Multiplicacion(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error: Division por cero!" << endl;
        return 0;
    }
}

typedef float (*Operation)(float, float);

int main() {
    Operation vpf[4] = {&Adicion, &Sustraccion, &Multiplicacion, &Division};

    float a, b, c;
    int opt;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    cout << "Ingresa la operacion (0-Adicion, 1-Sustraccion, 2-Multiplicacion, 3-Division): ";
    cin >> opt;

    if (opt >= 0 && opt < 4) {
        c = (*vpf[opt])(a, b);
        cout << "Resultado: " << c << endl;
    } else {
        cout << "Opcion invalida!" << endl;
    }

    return 0;
}

