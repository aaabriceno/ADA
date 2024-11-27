#include <iostream>
#include <vector>
#include <algorithm>

// Función para calcular el beneficio máximo
int BeneficioMaximo(const std::vector<std::vector<int>>& beneficios, int n, int r) {
    // Crear la tabla dp con r+1 proyectos y n+1 recursos
    std::vector<std::vector<int>> dp(r + 1, std::vector<int>(n + 1, 0));

    // Llenar la tabla
    for (int i = 1; i <= r; ++i) { // Para cada proyecto
        for (int k = 0; k <= n; ++k) { // Para cada cantidad de recursos disponibles
            dp[i][k] = dp[i - 1][k]; // No asignar recursos al proyecto i
            for (int j = 0; j <= k; ++j) { // Asignar j recursos al proyecto i
                dp[i][k] = std::max(dp[i][k], dp[i - 1][k - j] + beneficios[i - 1][j]);
            }
        }
    }

    return dp[r][n]; // Beneficio máximo
}

int main() {
    int n = 5; // Total de recursos disponibles
    int r = 3; // Número de proyectos

    // Matriz de beneficios N[i][j]: beneficio de asignar j unidades al proyecto i
    std::vector<std::vector<int>> beneficios = {
        {0, 10, 15, 40, 45, 50},  // Proyecto 1
        {0, 5, 25, 35, 50, 60},   // Proyecto 2
        {0, 2, 8, 20, 35, 50}     // Proyecto 3
    };

    // Calcular y mostrar el beneficio máximo
    int beneficioMaximo = BeneficioMaximo(beneficios, n, r);
    std::cout << "Beneficio máximo: " << beneficioMaximo << std::endl;

    return 0;
}
