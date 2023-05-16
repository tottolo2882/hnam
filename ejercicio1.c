#include <stdio.h>
#define n 10
int vector[n];
int i, suma=0;
int mayor();
int mayorloc;
void leer();
void imprimir();
float promedio();
float promedioloc;
int main()
{
 leer(vector);
 promedio(vector);
 mayor(vector);
 imprimir();
 return 0;
}
void leer()
{
 for ( i = 0; i < n; ++i)
 {
 printf("Ingrese el #%d\n", i+1);
 scanf("%d",&vector[i]);
 }
}
float promedio(int vector[]){
 for ( i = 0; i < n; ++i)
 {
 suma+=vector[i];
 }
 promedioloc=suma/n;
 return (promedioloc);
}
int mayor(int vector[]){
 mayorloc=0;
 for ( i = 0; i < n; ++i)
 {
 if(mayorloc<vector[i]){
 mayorloc=vector[i];
 }
 }
 return (mayorloc);
}
void imprimir(){
 for ( i = 0; i < n; ++i)
 {
 printf("El numero en la posicion %d es: %d\n", i+1, vector[i]);
 }
 printf("El promedio es: %f\n", promedioloc);
 printf("El mayor de los numeros es: %d\n", mayorloc);
}
