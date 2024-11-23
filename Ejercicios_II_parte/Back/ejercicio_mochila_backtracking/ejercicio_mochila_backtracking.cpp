#include <iostream>
#include <vector>
using namespace std;

struct Objeto {

    int peso, beneficio, cantidad_veces_objeto;

};

void mochila_backtracking(const vector<Objeto>& objetos, int caso_base, int capacidad_restante, vector<int>& seleccionActual, int beneficioActual,

    vector<int>& mejorSeleccion, int& mejor_beneficio) {

    if (caso_base == objetos.size()) {   // Caso base: si ya revisamos todos los objetos o no queda capacidad
        if (beneficioActual > mejor_beneficio) {
            mejor_beneficio = beneficioActual;
            mejorSeleccion = seleccionActual;
        }
        return;
    }



    for (int cantidad = 0; cantidad <= objetos[caso_base].cantidad_veces_objeto; ++cantidad) {
        int pesoUsado = cantidad * objetos[caso_base].peso;
        if (pesoUsado <= capacidad_restante) {
            seleccionActual[caso_base] = cantidad;
            mochila_backtracking(objetos, caso_base + 1, capacidad_restante - pesoUsado,
                seleccionActual, beneficioActual + cantidad * objetos[caso_base].beneficio,
                mejorSeleccion, mejor_beneficio);
        }
        else {
            break;
        }
    }
}


int main() {

    int cantidad_de_objetos = 4, peso_maximo = 12;
    vector<Objeto> objetos = {
        {2, 3, 2}, // obj1: peso = 2, beneficio = 3, cantidad = 2
        {3, 2, 2}, // obj2: peso = 3, beneficio = 2, cantidad = 2
        {4, 1, 2}, // obj3: peso = 4, beneficio = 1, cantidad = 2
        {1, 4, 3}  // obj4: peso = 1, beneficio = 4, cantidad = 3
    };



    vector<int> seleccionActual(cantidad_de_objetos, 0); // Selección actual de objetos
    vector<int> mejorSeleccion(cantidad_de_objetos, 0); // Mejor selección encontrada
    int mejor_beneficio = 0;
    mochila_backtracking(objetos, 0, peso_maximo, seleccionActual, 0, mejorSeleccion, mejor_beneficio);

    vector<int> beneficiosPorObjeto(cantidad_de_objetos, 0);
    vector<int> pesosPorObjeto(cantidad_de_objetos, 0);
    int pesoTotal = 0;

    for (int i = 0; i < cantidad_de_objetos; ++i) {
        beneficiosPorObjeto[i] = mejorSeleccion[i] * objetos[i].beneficio;
        pesosPorObjeto[i] = mejorSeleccion[i] * objetos[i].peso;
        pesoTotal += pesosPorObjeto[i];
    }

    cout << "\nSolucion:  ";
    for (int i = 0; i < cantidad_de_objetos; ++i) {
        cout << mejorSeleccion[i] << " ";
    }
    cout << endl;
    
    cout << "Beneficio: ";
    for (int i = 0; i < cantidad_de_objetos; ++i) {
        cout << beneficiosPorObjeto[i] << " ";
    }
    cout << endl;
    
    cout << "Peso:      ";
    for (int i = 0; i < cantidad_de_objetos; ++i) {
        cout << pesosPorObjeto[i] << " ";
    }
    cout << endl;
    
    cout << "\nPeso total usado: " << pesoTotal << " (Capacidad maxima: " << peso_maximo << ")" << endl;
    cout << "Mejor beneficio: " << mejor_beneficio << endl;

    return 0;

}