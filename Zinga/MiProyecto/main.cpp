#include <GL/glut.h> // Biblioteca OpenGL
#include <vector>
#include <iostream>

int cost = 0; // Variable global para almacenar el costo computacional

// Función para realizar el Bubble Sort y calcular el costo computacional
int bubbleSort(std::vector<int>& arr) {
	int n = arr.size();
	cost = 0; // Inicializa el costo
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			cost++; // Contabiliza la comparación
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				cost++; // Contabiliza el intercambio
			}
		}
	}
	return cost; // Devuelve el costo total del algoritmo
}

// Función para dibujar el gráfico en OpenGL
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Establece el color del gráfico (verde)
	glColor3f(0.0, 1.0, 0.0);
	
	// Normaliza el valor del costo para la gráfica (ajusta según sea necesario)
	float normalizedCost = cost / 100.0;  // Ajusta este valor según el rango de "cost"
	
	// Dibuja una barra que represente el costo computacional
	glBegin(GL_QUADS);
	glVertex2f(-0.1, -1.0);            // Esquina inferior izquierda
	glVertex2f(-0.1, -1.0 + normalizedCost); // Esquina superior izquierda (altura depende del costo)
	glVertex2f(0.1, -1.0 + normalizedCost);  // Esquina superior derecha
	glVertex2f(0.1, -1.0);             // Esquina inferior derecha
	glEnd();
	
	glFlush();
}

// Inicializa la ventana de OpenGL
void initOpenGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Fondo negro
	glOrtho(-1, 1, -1, 1, -1, 1); // Establece la proyección ortográfica
}

int main(int argc, char** argv) {
	std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
	cost = bubbleSort(arr); // Calcula el costo usando Bubble Sort
	
	std::cout << "El costo computacional es: " << cost << std::endl;  // Imprime en la consola
	
	// Inicializa OpenGL
	glutInit(&argc, argv);
	glutCreateWindow("Visualización del Costo Computacional");
	initOpenGL();
	
	// Establece la función de visualización
	glutDisplayFunc(display);
	
	// Entra en el bucle de OpenGL
	glutMainLoop();
	
	return 0;
}
