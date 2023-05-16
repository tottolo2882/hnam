#include <stdio.h>

void sumar(int *vector, int tam);

int main() {
 int numeros[] = {1, 2, 3, 4, 5};
 int tam = sizeof(numeros) / sizeof(int);
 int i;
 printf("Antes de la suma: ");
 	for (i = 0; i < tam; i++) {
	 printf("%d ", numeros[i]);
 }
 sumar(numeros, tam);
 printf("\nDespués de la suma: ");
 for ( i = 0; i < tam; i++) {
 printf("%d ", numeros[i]);
 }
 return 0;
}
void sumar(int *vector, int tam) {
	int i;
 		for (i = 0; i < tam; i++) {
 		*(vector + i) += 10;
 }
}
