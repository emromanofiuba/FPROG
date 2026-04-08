/*
Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero.
*/

#include <stdio.h>

int main(){
    int num_entero;

    printf("ingrese un numero entero: ");
    scanf("%i", &num_entero);

    if (num_entero%2 == 0)
        printf("El numero ingresado (%i) es par\n", num_entero);
    else
        printf("El numero ingresado (%i) es impar\n", num_entero);

    if (num_entero > 0)
        printf("El numero ingresado (%i) es positivo\n", num_entero);
    else if (num_entero < 0)
        printf("El numero ingresado (%i) es negativo\n", num_entero);
    else
        printf("El numero ingresado (%i) es cero\n", num_entero);

    return 0;
}