/*
Calcular y mostrar la suma de los n primeros números naturales. Siendo n un
número ingresado por el usuario. Usar fórmula [ n.(n+1) ] / 2
*/

#include <stdio.h>

void main(){
    int n, suma;

    printf("Ingrese un numero n: ");
    scanf("%i", &n);

    suma = (n*(n+1))/2;
    printf("\nLa suma de los primeros %i numeros naturales es %d\n", n, suma);
}