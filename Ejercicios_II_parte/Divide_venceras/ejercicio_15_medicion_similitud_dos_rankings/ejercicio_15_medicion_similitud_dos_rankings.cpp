/*
Diseñe y analice la eficiencia de un algoritmo "divide y vencerás" para medir la
similitud entre dos rankings.
 Muchos sitios web intentan comparar las preferencias de dos usuarios para
 realizar sugerencias a partir de las preferencias de usuarios con gustos similares
 a los nuestros. Dado un ranking de n productos (p.ej. canciones) mediante el cual
 los usuarios indicamos nuestras preferencias, un algoritmo puede medir la
 similitud de nuestras preferencias contando el número de inversiones:
 Dos productos i y j están "invertidos" en las preferencias de A y B si el usuario
 A prefiere el producto i antes que el j mientras que el usuario B prefiere el
 producto j antes que el i.
 Esto es, cuantas menos inversiones existan entre dos rankings, más similares
 serán las preferencias de los usuarios representados por esos rankings.

 NOTA: Un algoritmo de fuerza bruta compararía las preferencias de los
 usuarios probando todos los pares posibles de productos Θ(n^	2).
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Función para combinar y contar las inversiones en dos sub-rankings
int combinarYContarInversiones(vector<int>& ranking, vector<int>& temp, int bajo, int medio, int alto) {
    int inversiones = 0;

    int i = bajo;      // Índice para la primera mitad del ranking
    int j = medio + 1; // Índice para la segunda mitad del ranking
    int k = bajo;      // Índice para el array temporal

    while (i <= medio && j <= alto) {
        if (ranking[i] <= ranking[j]) {
            temp[k++] = ranking[i++];
        }
        else {
            // Contar inversiones al encontrar un elemento en la primera mitad mayor que uno en la segunda mitad
            inversiones += (medio - i + 1);
            temp[k++] = ranking[j++];
        }
    }

    // Completar la fusión si hay elementos restantes en la primera mitad
    while (i <= medio) {
        temp[k++] = ranking[i++];
    }

    // Completar la fusión si hay elementos restantes en la segunda mitad
    while (j <= alto) {
        temp[k++] = ranking[j++];
    }

    // Copiar el array temporal de vuelta al array original
    for (int l = bajo; l <= alto; ++l) {
        ranking[l] = temp[l];
    }

    return inversiones;
}

// Función principal para contar inversiones usando "divide y vencerás"
int contarInversiones(vector<int>& ranking, vector<int>& temp, int bajo, int alto) {
    int inversiones = 0;

    if (bajo < alto) {
        int medio = bajo + (alto - bajo) / 2;

        // Contar inversiones en la primera mitad y en la segunda mitad
        inversiones += contarInversiones(ranking, temp, bajo, medio);
        inversiones += contarInversiones(ranking, temp, medio + 1, alto);

        // Combinar y contar inversiones entre las dos mitades
        inversiones += combinarYContarInversiones(ranking, temp, bajo, medio, alto);
    }

    return inversiones;
}

// Función para medir la similitud entre dos rankings
int medirSimilitud(vector<int>& rankingA, vector<int>& rankingB) {
    int n = rankingA.size();
    unordered_map<int, int> posicionEnB;

    // Crear un mapeo de las posiciones de los productos en rankingB
    for (int i = 0; i < n; ++i) {
        posicionEnB[rankingB[i]] = i;
    }

    // Transformar rankingA en una secuencia de posiciones de rankingB
    vector<int> rankingATransformado(n);
    for (int i = 0; i < n; ++i) {
        rankingATransformado[i] = posicionEnB[rankingA[i]];
    }

    // Contar las inversiones en la secuencia transformada
    vector<int> temp(n);
    return contarInversiones(rankingATransformado, temp, 0, n - 1);
}

int main() {
    // Ejemplo de uso
    vector<int> rankingA = { 1, 2, 3, 4 };  // Preferencias del usuario A
    vector<int> rankingB = { 4, 3, 2, 1 };  // Preferencias del usuario B

    // Medir la similitud entre los dos rankings
    int inversiones = medirSimilitud(rankingA, rankingB);

    // Imprimir el resultado
    cout << "Numero de inversiones entre los dos rankings: " << inversiones << endl;

    return 0;
}
