/*
Diseñe y analice la eficiencia de un algoritmo "divide y vencerás" para encontrar
el par de puntos más cercano dentro de un conjunto de puntos en el plano.
Se podría diseñar un algoritmo "específico" para este problema calculando las
distancias entre todos los pares de puntos O(n2
), pero la técnica "divide y
vencerás" nos permite obtener una solución más eficiente de la siguiente forma:
a. Dividir: Se encuentra una línea vertical l que divide el conjunto P en dos
conjuntos PI
 y PD de forma que cada uno contiene la mitad de los puntos
en P. Todos los puntos en PI
 están a la izquierda de la línea l y todos los
puntos en PD se encuentran a la derecha. El vector X se divide en dos
subvectores XI
 y XD que contienen los puntos en PI
 y PD ordenados
según el valor de su coordenada x. De igual forma, el vector Y se divide
en dos arrays YI
 e YD que contienen los puntos de PI
 y PD, ordenados
según su coordenada y.
b. Resolver: Una vez divididos los vectores, se hacen las llamadas
recursivas para encontrar los puntos más cercanos en PI
 y PD. La primera
de ellas toma como argumentos los puntos PI
 y los vectores XI
 e YI
. La
segunda considera los puntos PD y los vectores XD e YD. Sean δI
 y δD las
distancias más pequeñas en PI
 y PD.
c. Combinar: Los puntos más cercanos son aquéllos que se encontraron a
menor distancia en las llamadas recursivas (δ = min{δI
, δD}) o bien es un
par con un punto en PI
 y otro en PD. El algoritmo, por tanto, debe
encontrar si existe un par a una distancia menor que δ. La clave está en
saber que estos puntos, de existir, se encuentran dentro de una ventana
con 2δ de ancho y δ de alto centrada alrededor de la línea l.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Estructura para representar un punto en el plano
struct Point {
    int x, y;
};

// Función para calcular la distancia euclidiana entre dos puntos
double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Función para comparar puntos en función de sus coordenadas x
bool compareByX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

// Función para comparar puntos en función de sus coordenadas y
bool compareByY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

// Función de fuerza bruta para encontrar el par de puntos más cercano en un conjunto pequeño
pair<Point, Point> bruteForceClosestPair(vector<Point>& points, int low, int high) {
    double minDistance = numeric_limits<double>::max();
    pair<Point, Point> closestPair;
    for (int i = low; i <= high; ++i) {
        for (int j = i + 1; j <= high; ++j) {
            double distance = calculateDistance(points[i], points[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestPair = { points[i], points[j] };
            }
        }
    }
    return closestPair;
}

// Función principal para encontrar el par de puntos más cercano
pair<Point, Point> findClosestPair(vector<Point>& pointsByX, vector<Point>& pointsByY, int low, int high) {
    if (high - low <= 3) {
        // Caso base: usar fuerza bruta para conjuntos pequeños de puntos
        return bruteForceClosestPair(pointsByX, low, high);
    }

    // División del conjunto en dos partes
    int mid = low + (high - low) / 2;
    Point midPoint = pointsByX[mid];

    vector<Point> leftPointsByY, rightPointsByY;
    for (const Point& point : pointsByY) {
        if (point.x <= midPoint.x) {
            leftPointsByY.push_back(point);
        }
        else {
            rightPointsByY.push_back(point);
        }
    }

    // Recursión en ambas mitades
    pair<Point, Point> leftClosestPair = findClosestPair(pointsByX, leftPointsByY, low, mid);
    pair<Point, Point> rightClosestPair = findClosestPair(pointsByX, rightPointsByY, mid + 1, high);

    // Encontrar la distancia mínima entre las dos mitades
    double minDistance = min(calculateDistance(leftClosestPair.first, leftClosestPair.second),
        calculateDistance(rightClosestPair.first, rightClosestPair.second));
    pair<Point, Point> closestPair = (calculateDistance(leftClosestPair.first, leftClosestPair.second) <
        calculateDistance(rightClosestPair.first, rightClosestPair.second)) ?
        leftClosestPair : rightClosestPair;

    // Construir un vector de puntos dentro de la franja central
    vector<Point> strip;
    for (const Point& point : pointsByY) {
        if (abs(point.x - midPoint.x) < minDistance) {
            strip.push_back(point);
        }
    }

    // Encontrar el par de puntos más cercano en la franja central
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDistance; ++j) {
            double distance = calculateDistance(strip[i], strip[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestPair = { strip[i], strip[j] };
            }
        }
    }

    // Devolver el par de puntos más cercano entre las dos mitades
    return closestPair;
}

int main() {
    // Ejemplo de uso
    vector<Point> points = { {0, 0}, {1, 1}, {8, 2}, {12, 3}, {4, 23}, {5,25} };

    // Ordenar puntos por coordenada x y y
    vector<Point> pointsByX = points;
    vector<Point> pointsByY = points;
    sort(pointsByX.begin(), pointsByX.end(), compareByX);
    sort(pointsByY.begin(), pointsByY.end(), compareByY);

    // Encontrar el par de puntos más cercano
    pair<Point, Point> closestPair = findClosestPair(pointsByX, pointsByY, 0, points.size() - 1);

    // Imprimir el resultado
    cout << "Par de puntos mas cercanos: (" << closestPair.first.x << ", " << closestPair.first.y << ") y ("
        << closestPair.second.x << ", " << closestPair.second.y << ")\n";

    return 0;
}
