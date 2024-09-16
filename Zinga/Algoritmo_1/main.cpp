#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <string>

// Variables globales para almacenar los datos
std::vector<float> n_values;
std::vector<float> cost_values;

// Define el costo del primer bucle interno
int cost_first_inner_loop(int n, int i) {
	return (n - i) / 2;
}

// Define el costo del segundo bucle interno
int cost_second_inner_loop(int i) {
	return i;
}

// Calcula el costo total
int total_cost(int n) {
	int cost_total = 0;
	int i = 0;
	while (i <= n) {
		int k = i;
		while (k <= n) {
			k = k + 2;
		}
		k = 1;
		while (k <= i) {
			k = k + 1;
		}
		i = i + 2;
		// Acumulamos el costo total basado en el algoritmo
		cost_total += (n - i) / 2 + i;
	}
	return cost_total;
}

// Genera los datos para la gráfica
void generate_data() {
	int max_n = 20; // Cambia según sea necesario
	
	for (int n = 0; n <= max_n; n += 2) {
		int cost = total_cost(n);
		n_values.push_back(n);
		cost_values.push_back(cost);
	}
}

// Función para dibujar texto
void renderBitmapString(float x, float y, void *font, const std::string &str) {
	glRasterPos2f(x, y);
	for (char c : str) {
		glutBitmapCharacter(font, c);
	}
}

// Dibuja los ejes
void draw_axes() {
	glColor3f(0.0, 0.0, 0.0); // Color de los ejes (negro)
	glBegin(GL_LINES);
	
	// Eje X
	glVertex2f(0, 0);
	glVertex2f(25, 0);
	
	// Eje Y
	glVertex2f(0, 0);
	glVertex2f(0, 120);
	
	glEnd();
	
	// Etiquetas del eje X
	glColor3f(0.0, 0.0, 0.0); // Color de las etiquetas (negro)
	for (int x = 0; x <= 25; x += 5) { // Ajustado a 5
		renderBitmapString(x, -5, GLUT_BITMAP_HELVETICA_12, std::to_string(x));
	}
	
	// Etiquetas del eje Y
	for (int y = 0; y <= 120; y += 10) { // Ajustado a 10
		renderBitmapString(-8, y, GLUT_BITMAP_HELVETICA_12, std::to_string(y));
	}
}

// Dibuja la cuadrícula
void draw_grid() {
	glColor3f(0.8, 0.8, 0.8); // Color de la cuadrícula (gris claro)
	glBegin(GL_LINES);
	
	// Líneas horizontales
	for (int y = 0; y <= 120; y += 5) { // Cambia el intervalo a 5
		glVertex2f(0, y);
		glVertex2f(25, y);
	}
	
	// Líneas verticales
	for (int x = 0; x <= 25; x += 1) { // Cambia el intervalo a 1
		glVertex2f(x, 0);
		glVertex2f(x, 120);
	}
	
	glEnd();
}

// Función de display para OpenGL
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Dibuja la cuadrícula y los ejes
	draw_grid();
	draw_axes();
	
	glColor3f(1.0, 0.0, 0.0); // Color de la línea (rojo)
	glBegin(GL_LINE_STRIP);
	for (size_t i = 0; i < n_values.size(); ++i) {
		glVertex2f(n_values[i], cost_values[i]);
	}
	glEnd();
	
	glutSwapBuffers();
}

// Configuración inicial
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 25, 0, 120, -1, 1); // Ajusta el rango según tus datos
}

int main(int argc, char** argv) {
	generate_data(); // Generar los datos
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Costo Computacional");
	
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
