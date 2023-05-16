#include <stdio.h>

int main() {
 // Definir las matrices a sumar y la matriz resultante
 	int matriz1[2][2] = {{1, 2}, {3, 4}};
 	int matriz2[2][2] = {{5, 6}, {7, 8}};
 	int matrizResultado[2][2];
 	int i, j;

 // Verificar que las dimensiones de las matrices sean iguales
 	if (sizeof(matriz1) != sizeof(matriz2)) {
 	printf("Error: Las matrices deben tener la misma dimensión.\n");
 	return 1;
 }

 // Recorrer ambas matrices y sumar los elementos correspondientes
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
		matrizResultado[i][j] = matriz1[i][j] + matriz2[i][j];
 }
 }

 // Imprimir la matriz resultante
	 printf("La matriz resultante es:\n");
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				 printf("%d ", matrizResultado[i][j]);
	 		}
	 printf("\n");
	 }

 return 0;
}
