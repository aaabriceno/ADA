#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int optimalCacheMisses(const vector<int>& requests, int cacheSize) {
    unordered_set<int> cache; // Datos en la caché
    unordered_map<int, int> nextUse; // Próxima aparición de cada dato
    int misses = 0;

    for (size_t i = 0; i < requests.size(); ++i) {
        int current = requests[i];

        // Actualizamos las próximas apariciones
        nextUse.clear();
        for (size_t j = i + 1; j < requests.size(); ++j) {
            if (nextUse.find(requests[j]) == nextUse.end()) {
                nextUse[requests[j]] = j;
            }
        }

        // Si el dato no está en la caché
        if (cache.find(current) == cache.end()) {
            misses++;
            if (cache.size() == cacheSize) {
                // Reemplazo óptimo: eliminar el que se usará más tarde o no se usará
                int toRemove = -1, farthestUse = -1;
                for (int cached : cache) {
                    if (nextUse.find(cached) == nextUse.end()) {
                        toRemove = cached;
                        break;
                    }
                    if (nextUse[cached] > farthestUse) {
                        farthestUse = nextUse[cached];
                        toRemove = cached;
                    }
                }
                cache.erase(toRemove);
            }
            cache.insert(current);
        }
    }

    return misses;
}

int main() {
    // Ejemplo de solicitudes conocidas
    vector<int> requests = { 1, 2, 3, 4, 2, 1, 3, 7, 1, 2 };
    int cacheSize = 3;

    cout << "Numero minimo de fallos de cache: "
        << optimalCacheMisses(requests, cacheSize) << endl;

    return 0;
}
